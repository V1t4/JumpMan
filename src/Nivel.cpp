#include "Nivel.h"

Nivel::Nivel() {
	
	//Inicializo la camara
	camara.reset(sf::FloatRect(0,Global::altoMundo-Global::altoVentana, Global::anchoVentana, Global::altoVentana));
	camara.setViewport(sf::FloatRect(0, 0, 1, 1));
	
	//Cargo el nivel desde un archivo, determinando el nivel actual
	stringstream nomArchi;
	nomArchi<<"assets/levels/nivel"<<Global::nivActual<<".ni";
	cargarNivel(nomArchi.str());
	
	//Ubico al jugador en su posicion inicial
	p.inicializar(Global::t_personaje);
	
	//Cargo el texto que se mostrara en la esquina superior izquierda
	texto.setFont(Global::fuente);
	texto.setFillColor(sf::Color(255,91,0));
	texto.setCharacterSize(40);
}

void Nivel::actualizar (Juego &j) {
	
	//Actualiza el personaje
	p.actualizar(Su);
	
	//Actualiza el suelo
	for(size_t i=0;i<Su.size();i++)	Su[i]->actualizar();
	
	//Actualiza los enemigos
	for(size_t i=0;i<En.size();i++) En[i]->actualizar();
	
	//Actualiza las llaves
	for(size_t i=0;i<Ll.size();i++) Ll[i]->actualizar(p);
	
	//Mueve la camara
	moverCamara();
	
	//Actualiza el string del texto para que muestre el tiempo, las llaves tomadas/restantes y el nro de nivel
	actualizarTexto(j.verTiempo());
	
	//Si el jugador toca la puerta con todas las llaves...
	if ((p.posicionPersonaje().intersects(puerta.posicionPuerta()))&&(p.llavesActuales()==Ll.size())) {
		camara.reset(sf::FloatRect(0,0,Global::anchoVentana,Global::altoVentana));
		
		++Global::nivActual;
		if(Global::nivActual==Global::cantNiv+1){//...y llego al final del juego
			Global::tiempoJugador=j.verTiempo();//Se registra el tiempo
			j.cambiarEscena(new Final());//Se muestra la escena final
			
		}else{//...y todavia no jugo el ultimo nivel
			j.cambiarEscena(new Nivel());//Llama a otro nivel
		}
	}
	
	if (p.posicionPersonaje().top>1800) {//Si el personaje se cae
		camara.reset(sf::FloatRect(0,0,Global::anchoVentana,Global::altoVentana));
		j.cambiarEscena(new GameOver());//GameOver
	}
	
	for(size_t i=0;i<En.size();i++) { //Si el personaje toca un enemigo
		if ((p.posicionPersonaje().intersects(En[i]->posicionEnemigo()))){
			camara.reset(sf::FloatRect(0,0,Global::anchoVentana,Global::altoVentana));
			j.cambiarEscena(new GameOver());//GameOver
		}
	}
}

void Nivel::dibujar (sf::RenderWindow &ventana) {//Dibujado del Nivel
	ventana.clear(sf::Color::Cyan);
	
	ventana.setView(camara);//Ubica la camara
	
	for(size_t i=0;i<Ll.size();i++) { //Dibuja cada llave por separado si todavia no fue tomada
		if(!Ll[i]->eliminada()) Ll[i]->dibujar(ventana);
	}
	
	puerta.dibujar(ventana);//Dibuja la Puerta
	
	p.dibujar(ventana);//Dibuja al Personaje
	
	for(size_t i=0;i<Su.size();i++) {//Dibuja cada porcion del suelo por separado 
		Su[i]->dibujar(ventana);
	}
	
	for(size_t i=0;i<En.size();i++) { //Dibuja cada enemigo por separado
		En[i]->dibujar(ventana);
	}
	
	ventana.draw(texto);//Dibuja el texto
	
}

void Nivel::cargarNivel (string archBin) { //Carga el nivel desde un archivo
	
	ifstream archi(archBin.c_str(), ios::binary | ios::ate);//Archivo solo para lectura
	
	//Chequea que se encontro
	if(!archi.is_open()) {
		std::cerr<<"Archivo generador de nivel "<<archBin<<" no encontrado"<<std::endl;
		abort();
	}
	
	//Chequea que es valido para el mundo a generar
	if(archi.tellg()!=((Global::altoMundo)*(Global::anchoMundo)/(Global::tamanoCuadro*Global::tamanoCuadro))) {
		std::cerr<<"Archivo generador de nivel invalido"<<std::endl;
		abort();
	}
	archi.seekg(0);
	char x;
	//Crea los distintos elementos y los ubica donde corresponde
	for(float j=0;j<Global::altoMundo/Global::tamanoCuadro;j++) { 
		for(float i=0;i<Global::anchoMundo/Global::tamanoCuadro;i++) { 
			archi.read(reinterpret_cast<char*>(&x),sizeof(x));
			switch (x){
			case 'p': Su.push_back(new Pasto(i*Global::tamanoCuadro,j*Global::tamanoCuadro)); break;
			case 'r': Su.push_back(new Piedra(i*Global::tamanoCuadro,j*Global::tamanoCuadro)); break;
			case 'a': Su.push_back(new Arena(i*Global::tamanoCuadro,j*Global::tamanoCuadro)); break;
			case 'v': Su.push_back(new Vertical((i-1)*Global::tamanoCuadro,j*Global::tamanoCuadro)); 
			Su.push_back(new Vertical(i*Global::tamanoCuadro,j*Global::tamanoCuadro)); 
			Su.push_back(new Vertical((i+1)*Global::tamanoCuadro,j*Global::tamanoCuadro)); break;//Siempre se crean de a tres
			case 'h': Su.push_back(new Horizontal((i-1)*Global::tamanoCuadro,j*Global::tamanoCuadro)); 
			Su.push_back(new Horizontal(i*Global::tamanoCuadro,j*Global::tamanoCuadro)); 
			Su.push_back(new Horizontal((i+1)*Global::tamanoCuadro,j*Global::tamanoCuadro)); break;//Siempre se crean de a tres
			case 'i': Su.push_back(new Hielo(i*Global::tamanoCuadro,j*Global::tamanoCuadro)); break;
			case 'l': Ll.push_back(new Llave(i*Global::tamanoCuadro,j*Global::tamanoCuadro,Global::t_llave)); break;
			case 'e': En.push_back(new Enemigo(i*Global::tamanoCuadro,j*Global::tamanoCuadro,Global::t_enemigo)); break;
			case 'd':
				if(puerta.estaUbicada()) {//Si ya se ubico la puerta, hay un error en el archivo ya que solo puede haber una
					std::cerr<<"Error: el nivel tiene mas de una puerta"<<std::endl;
					abort();
				}
				puerta.Ubicar(i*Global::tamanoCuadro,j*Global::tamanoCuadro,Global::t_puerta); break;
				
			}
		}
	}
	
	if(!puerta.estaUbicada()) {//Si al final de la carga no se agrega ninguna, el nivel no tiene solucion
		std::cerr<<"Error: el nivel no tiene puertas"<<std::endl;
		abort();
	}
}

void Nivel::moverCamara ( ) {// Se mueve la camara para que tenga de centro al personaje
	
	//En x es la posicion en x mas el ancho del Personaje menos la mitad del ancho de la pantalla
	posicionCamara.x= p.posicionPersonaje().left + p.posicionPersonaje().width - Global::anchoVentana/2;
	//En y es la posicion en y mas el alto del Personaje menos la mitad del alto de la pantalla
	posicionCamara.y= p.posicionPersonaje().top + p.posicionPersonaje().height - Global::altoVentana/2;
	
	//Si el personaje esta en la mitad izquierda de la pantalla, en el extremo izquierdo del nivel, la camara no se mueve
	if (posicionCamara.x< 0) posicionCamara.x = 0;
	
	//Si el personaje esta en la mitad derecha de la pantalla, en el extremo derecho del nivel, la camara no se mueve
	if (posicionCamara.x> Global::anchoMundo-Global::anchoVentana) posicionCamara.x = Global::anchoMundo-Global::anchoVentana;
	
	//Si el personaje esta en la mitad superior de la pantalla, en el extremo superior del nivel, la camara no se mueve
	if (posicionCamara.y< 0) posicionCamara.y = 0;
	
	//Si el personaje esta en la mitad inferior de la pantalla, en el extremo inferior del nivel, la camara no se mueve
	if (posicionCamara.y> Global::altoMundo-Global::altoVentana) posicionCamara.y = Global::altoMundo-Global::altoVentana;
	
	camara.reset(sf::FloatRect(posicionCamara.x, posicionCamara.y, Global::anchoVentana,Global::altoVentana));
}

void Nivel::actualizarTexto (float tiempo) {
	
	//Se ubica al texto en la esquina superior izquierda
	texto.setPosition(posicionCamara.x+20,posicionCamara.y+20);
	
	//Se actualiza el texto para que diga el tiempo, las llaves y los niveles
	stringstream s;
	
	s<<Global::txt_nivel[0]<<": "<<Global::nivActual<<"/"<<Global::cantNiv<<"\n"<<Global::txt_nivel[1]<<": "<<p.llavesActuales()
		<<"/"<<Ll.size()<<"\n"<<Global::txt_nivel[2]<<": "<<setprecision(4)<<tiempo<<" s";
	texto.setString(s.str());
}

Nivel::~Nivel ( ) {//Borro todos los punteros dinamicos
	for(size_t i=0;i<Su.size();i++) { 
		delete Su[i];
	}
	for(size_t i=0;i<Ll.size();i++) { 
		delete Ll[i];
	}
	for(size_t i=0;i<En.size();i++) { 
		delete En[i];
	}
}
