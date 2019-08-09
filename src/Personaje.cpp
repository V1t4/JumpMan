#include "Personaje.h"

Personaje::Personaje() {
	
}

void Personaje::inicializar(sf::Texture &t){
	//Ubico al personaje en su posicion inicial y cargo su textura, determinando como sera al principio
	sp.setTexture(t);
	sp.setTextureRect(sf::IntRect(0,0,54,88));
	sp.setPosition(20,Global::altoMundo-posicionPersonaje().height-Global::tamanoCuadro*5);
	
	//Inicializo las variables auxiliares
	caida=5;
	tiempoCayendo=0;
	alturaSaltada=0;
	estaSaltando=false;
	estaParado=false;
	nroLlaves=0;
	
	direccion=0;
	estado=1;
	cambioEstado=0;
	
}

void Personaje::dibujar (sf::RenderWindow & ventana){//Dibujado del personaje
	ventana.draw(sp);
}

void Personaje::actualizar (std::vector <Suelo*> &Su){
	//Si esta quieto, el sprite mostrado es el de la imagen izquierda de la textura, la posicion 0 en x
	if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)||sf::Keyboard::isKeyPressed(sf::Keyboard::D))&&
		 !(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)||sf::Keyboard::isKeyPressed(sf::Keyboard::A))) 
		 estado=0;
	else {//Si se mueve, se alternan las imagenes de tal forma que parezca que camina
		if(cambioEstado==15){
			cambioEstado=0;
			estado++;
		};
		
		if(estado==7) estado=1;//Si llego al final de la imagen, la recorre desde el principio sin pasar por la textura del reposo
		
		cambioEstado++;
	}
	
	//Si se apretan las teclas designadas, el personaje se mueve
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)||sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		moverse(derecha,Su);//Moverse a la derecha chequeando si choca/roza con el suelo
		direccion=0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		moverse(izquierda,Su);//Moverse a la izquierda chequeando si choca/roza con el suelo
		direccion=1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		saltar(Su);//Saltar viendo si el suelo ayuda a ir mas alto o mas bajo
	}else{//Si se suelta la tecla arriba
		estaSaltando=false;//Se resetea el estado saltando
	}
	if(!estaSaltando) {//Si no esta saltando, esta cayendo
		if(tiempoCayendo%15){
			caida+=tiempoCayendo/5;
		}
		sp.move(0,caida);
		tiempoCayendo++;
	}
	while(TocaSuelo(Su,arriba)){//Si llego al piso
		//Se reestablecen las variables cambiadas durante el salto o la caida
		estaParado=true;
		tiempoCayendo=0;
		caida=5;
		sp.move(0,-1);//Se acomoda para que deje de tocarlo y evitar colisiones laterales
		if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) alturaSaltada=0;
	}
	if(estaParado){//Si esta parado sobre un suelo, pregunta cuanto se mueve
		sp.move(seMueveSuelo(Su));
	}
	
	//Limites de movimiento del personaje
	sf::Vector2f vp=sp.getPosition();
	//Limite derecho
	if (vp.x>Global::anchoMundo-posicionPersonaje().width-20) vp.x=Global::anchoMundo-posicionPersonaje().width-20;
	//Limite izquierdo
	if (vp.x<20) vp.x=20;
	//No hacen falta los limites verticales
	
	sp.setPosition(vp);//Establece la nueva posicion del personaje.
	actualizarSprite();//Se actualiza el sprite para que parezca que camina
}

bool Personaje::TocaSuelo(std::vector <Suelo*> &Su, lado l) {//Verificacion de la colision entre suelo y personaje
	
	for(size_t i=0;i<Su.size();i++) { //Verifica se intesecta a cada una de las porciones de suelo
		if (posicionPersonaje().intersects(Su[i]->posicionSuelo())) {//Si es asi, se fija si lo hace desde donde interesa
			switch (l) {//l es el lado desde donde se pregunta si se tocan
			case derecha: if(((posicionPersonaje().left)+(posicionPersonaje().width))>(Su[i]->posicionSuelo().left)) return true;
			case izquierda: if((posicionPersonaje().left)<((Su[i]->posicionSuelo().left)+(Su[i]->posicionSuelo().width))) return true;
			case arriba: if (((posicionPersonaje().top)+(posicionPersonaje().height))>(Su[i]->posicionSuelo().top)) return true;
			case abajo: if((posicionPersonaje().top)<((Su[i]->posicionSuelo().top)+(Su[i]->posicionSuelo().height))) return true;
			};
		}
	}
	
	return false;
}

void Personaje::saltar (std::vector <Suelo*> &Su) {
	if(estaSaltando){//Si esta saltando, sube hasta la altura maxima
		if(maxSalto==-1){
			alturaSaltada=-1;
			estaSaltando=false;
			return; //la altura maxima es -1 cuando no esta tocando el suelo
		}
		sp.move(0,-15);
		alturaSaltada+=15;
		if(TocaSuelo(Su,abajo)){
			sp.move(0,15);
			estaSaltando=false;
		}
		if(alturaSaltada==maxSalto){//Cuando llega, deja de saltar
			estaSaltando=false;
		}
	}else{//Sino, no empezo a saltar o esta cayendo
		if(alturaSaltada==0){//Si no empezo a saltar, empieza el salto
			estaSaltando=true;
			maxSalto=determinarAlturaMaxima(Su);
			estaParado=false;
		}//Si esta cayendo, no necesita ayuda del metodo para moverse ya que la caida se da en actualizar()
	}
}

sf::FloatRect Personaje::posicionPersonaje ( ) {
	//Retorna un rectangulo con la posicion del personaje
	return sp.getGlobalBounds();
}

void Personaje::moverse (lado l, std::vector<Suelo*> & Su) {
	float movimiento=10;//Movimiento por defecto
	if(estaParado) movimiento-=rozamiento(Su);//Si esta parado, se resta por el rozamiento
	if(l==izquierda) movimiento*=-1;//Si se mueve a la izquierda, invierte la direccion
	sp.move(movimiento,0);//Se mueve
	if (TocaSuelo(Su,l)) sp.move(-movimiento,0);//Si choca con el suelo, retrocede. Visualmente, no se mueve
}

float Personaje::rozamiento (std::vector<Suelo*> & Su) {//Verifica si le afecta el rozamiento de algun suelo
	//Para eso, se crea un rectangulo debajo del personaje y se evalua si este intersecta el suelo
	sf::FloatRect Raux(posicionPersonaje().left,posicionPersonaje().top+posicionPersonaje().height,posicionPersonaje().width,10);
	for(size_t i=0;i<Su.size();i++) { 
		if(Su[i]->posicionSuelo().intersects(Raux)){
			return Su[i]->rozamiento();//Si es asi, se le pide el rozamiento
		}
	}
	return 0;
}

float Personaje::determinarAlturaMaxima(std::vector<Suelo*> & Su) {//De forma similar al rozamiento, se determina que tan alto llega
	//La diferencia es que se pide la dureza del suelo
	sf::FloatRect Raux(posicionPersonaje().left,posicionPersonaje().top+posicionPersonaje().height,posicionPersonaje().width,10);
	for(size_t i=0;i<Su.size();i++) { 
		if(Su[i]->posicionSuelo().intersects(Raux)){
			return Su[i]->dureza()*15+180;
		}
	}
	return -1;//Esto esta hecho para que no salte a menos que toque el suelo
}

sf::Vector2f Personaje::seMueveSuelo (std::vector<Suelo*> & Su) {//De manera similar al rozamiento, se pregunta cuanto se mueve el suelo
	sf::FloatRect Raux(posicionPersonaje().left,posicionPersonaje().top+posicionPersonaje().height,posicionPersonaje().width,10);
	for(size_t i=0;i<Su.size();i++) { 
		if(Su[i]->posicionSuelo().intersects(Raux)){
			return Su[i]->seMueve();
		}
	}
	return sf::Vector2f(0,0);
}

int Personaje::llavesActuales ( ) {//Retorna cuantas llaves tiene el jugador
	return nroLlaves;
}

void Personaje::tomarLlave ( ) {//Se toma la llave
	nroLlaves++;
}

void Personaje::actualizarSprite ( ) {
	//Se determina en que posicion esta el rectangulo que determina la textura del personaje
	sp.setTextureRect(sf::IntRect(estado*54,direccion*88,54,88));
}
