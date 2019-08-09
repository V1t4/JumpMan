#include "Final.h"

Final::Final() {
	//Se inicializan los textos
	titulo1.setFont(Global::fuente);
	titulo1.setColor(sf::Color::Yellow);
	titulo1.setString("FELICITACIONES!!!");
	titulo1.setCharacterSize(100);
	titulo1.setPosition(sf::Vector2f((Global::anchoVentana-titulo1.getLocalBounds().width)/2.0, 50));
	titulo2.setFont(Global::fuente);
	titulo2.setColor(sf::Color::Yellow);
	titulo2.setString("Ha ganado el juego!!!");
	titulo2.setCharacterSize(80);
	titulo2.setPosition(sf::Vector2f((Global::anchoVentana-titulo2.getLocalBounds().width)/2.0, 150));
	titulo3.setFont(Global::fuente);
	titulo3.setColor(sf::Color::White);
	stringstream s;//Esto es para concatenar el tiempo y el nombre del jugador en una misma frase
	s<<"Su tiempo es "<<setprecision(4)<<Global::tiempoJugador;
	titulo3.setString(s.str());
	titulo3.setCharacterSize(50);
	titulo3.setPosition(sf::Vector2f((Global::anchoVentana-titulo3.getLocalBounds().width)/2.0, 250));
	titulo4.setString("Por favor ingrese nombre (maximo 25 letras): ");
	titulo4.setFont(Global::fuente);
	titulo4.setColor(sf::Color::Red);
	titulo4.setCharacterSize(50);
	titulo4.setPosition(75, 360);
	
	nombre.setFont(Global::fuente);
	nombre.setColor(sf::Color::White);
	nombre.setCharacterSize(50);
	nombre.setPosition(sf::Vector2f(80+titulo4.getGlobalBounds().width, 360));
	nombre.setMaxChars(25);
	nombre.setSingleWord(true);
	
	presioneTecla1.setFont(Global::fuente);
	presioneTecla1.setColor(sf::Color::White);
	presioneTecla1.setString("Presione ENTER para volver a jugar");
	presioneTecla1.setCharacterSize(40);
	presioneTecla1.setPosition(sf::Vector2f((Global::anchoVentana-presioneTecla1.getLocalBounds().width)/2.0, 500));
	presioneTecla2.setFont(Global::fuente);
	presioneTecla2.setColor(sf::Color::White);
	presioneTecla2.setString("Presione TAB para ver los mejores tiempos");
	presioneTecla2.setCharacterSize(40);
	presioneTecla2.setPosition(sf::Vector2f(Global::anchoVentana-presioneTecla2.getLocalBounds().width-60, 575));
	presioneTecla3.setFont(Global::fuente);
	presioneTecla3.setColor(sf::Color::White);
	presioneTecla3.setString("Presione SPACE para volver al menu");
	presioneTecla3.setCharacterSize(40);
	presioneTecla3.setPosition(sf::Vector2f(75, 575));
	
	//Se agrega un margen
	margen.setTexture(Global::t_margen);
}

void Final::dibujar (sf::RenderWindow & ventana) {
	ventana.clear(sf::Color::Green);
	ventana.draw(margen);
	ventana.draw(titulo1);
	ventana.draw(titulo2);
	ventana.draw(titulo3);
	ventana.draw(titulo4);
	ventana.draw(nombre);
	ventana.draw(presioneTecla1);
	ventana.draw(presioneTecla2);
	ventana.draw(presioneTecla3);
	ventana.display();
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

