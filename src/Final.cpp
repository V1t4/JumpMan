#include "Final.h"

Final::Final() {
	//Se inicializan los textos
	titulo.setFont(Global::fuente);
	titulo.setFillColor(sf::Color::White);
	stringstream s;
	s<<setprecision(4)<<Global::tiempoJugador<<" s";
	titulo.setString(s.str());
	titulo.setCharacterSize(50);
	titulo.setPosition(sf::Vector2f(Global::txt_final[2].getLocalBounds().width + 
									Global::txt_final[2].getPosition().x + 20, 250));
	
	nombre.setFont(Global::fuente);
	nombre.setFillColor(sf::Color::White);
	nombre.setCharacterSize(50);
	nombre.setPosition(sf::Vector2f(20 + Global::txt_final[3].getGlobalBounds().width
									+ Global::txt_final[3].getPosition().x, 360));
	nombre.setMaxChars(25);
	nombre.setSingleWord(true);
	
	//Se agrega un margen
	margen.setTexture(Global::t_margen);
}

void Final::dibujar (sf::RenderWindow & ventana) {
	ventana.clear(sf::Color::Green);
	ventana.draw(margen);
	ventana.draw(titulo);
	ventana.draw(nombre);

	for (sf::Text linea : Global::txt_final)
		ventana.draw(linea);

}

void Final::actualizar (Juego &j) {
	nombre.update();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){//Si se presiona enter, se vuelve a jugar
		if(nombre.getValue()!="") Global::jugador=nombre.getValue();//Si se escribio algo, cambia el nombre del jugador
		else return;
		guardarTiempo();
		
		Global::nivActual=1;
		j.cambiarEscena(new Nivel());
	}
	//Con space, se regresa al menu
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if(nombre.getValue()!="") Global::jugador=nombre.getValue();//Si se escribio algo, cambia el nombre del jugador
		else return;
		guardarTiempo();
		
		j.cambiarEscena(new Menu());
	}
	//Con tab se ve la tabla de puntajes
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
		if(nombre.getValue()!="") Global::jugador=nombre.getValue();//Si se escribio algo, cambia el nombre del jugador
		else return;
		guardarTiempo();
		
		j.cambiarEscena(new VerTiempos());
	}
	
}



void Final::procesarEvento (const sf::Event & evento) {
	//Se llama al metodo procesarEvento de la clase InputText
	nombre.processEvent(evento);
}

void Final::guardarTiempo ( ) {
	fstream archi("assets/scores/MejoresTiempos.ti",ios::binary|ios::in|ios::out);//Se carga el archivo
	if(!archi.is_open()) std::cerr<<"No se encontro el archivo"<<std::endl;//Aviso de que no se encontro
	char n_aux[26]; float t_aux;
	char n_jug[26]; float t_jug=Global::tiempoJugador;
	strcpy(n_jug,Global::jugador.c_str());
	int pos=0;
	//Primero se recorre el archivo viendo donde deberia ubicarse
	while(archi.read(n_aux,sizeof(n_aux))&& archi.read(reinterpret_cast<char*>(&t_aux),sizeof(t_aux))){
		if(t_aux>t_jug) break;
		pos=archi.tellg();
	}
	archi.seekp(pos);
	archi.write(n_jug,sizeof(n_jug));
	archi.write(reinterpret_cast<char*>(&t_jug),sizeof(t_jug));
	pos=archi.tellg();
	strcpy(n_jug,n_aux); t_jug=t_aux;
	//Luego lo recorre desde alli para correr los lugares. Siempre son 10 lugares. Si no puede leer es porque llego
	//al decimo y no escribe nada
	while(archi.read(n_aux,sizeof(n_aux))&&archi.read(reinterpret_cast<char*>(&t_aux),sizeof(t_aux))){
		archi.seekp(pos);
		archi.write(n_jug,sizeof(n_jug));
		archi.write(reinterpret_cast<char*>(&t_jug),sizeof(t_jug));
		pos=archi.tellg();
		strcpy(n_jug,n_aux); t_jug=t_aux;
	}
}

