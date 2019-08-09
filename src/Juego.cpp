#include "Juego.h"
#include "Menu.h"
#include "Global.h"
#include "Nivel.h"
#include "Final.h"
#include "GameOver.h"
#include "Creditos.h"
#include <iostream>
#include "VerTiempos.h"

Juego::Juego() {
	//Inicializo la ventana
	ventana.create(sf::VideoMode(Global::anchoVentana,Global::altoVentana),"Proyecto POO");//Creacion de la ventana de Nivel
	ventana.setFramerateLimit(60);//Recomendado para que se actualice 60 veces por segundo
	
	Global::CargarTexturas();//Se llama al metodo que cargue las texturas y fuentes una sola vez
	
	escActual=new Menu();//El juego arranca mostrando el menu
	escSiguiente=nullptr;//Mientras la siguiente sea nullptr, seguiremos en la actual. Si no, se cambia de escena
}

void Juego::correr ( ) {
	while(ventana.isOpen()) {//Mientras la ventana este abierta, 
		sf::Event evento;
		while(ventana.pollEvent(evento)) {
			escActual->procesarEvento(evento);
			if(evento.type == sf::Event::Closed){
				ventana.close(); //Si se hace click en la X, la ventana se cierra
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) ventana.close();
		}
		
		escActual->actualizar(*this);//Llama al metodo actualizar de la escena
		escActual->dibujar(ventana);//Llama al metodo dibujar de la escena
		
		ventana.display();
		
		if(escSiguiente!=nullptr){//Si hay que cambiar escena
			if(Global::nivActual==Global::cantNiv+1)//Si el nivel actual es mayor que la cantidad de niveles, el jugador gano
				Global::nivActual=0;//y se vuelve el contador de niveles a 0
			delete escActual;//Se borra la escena actual
			escActual=escSiguiente;//Cambia a la siguiente
			escSiguiente=nullptr;//Se vuelve a anular la escena
			if(Global::nivActual==1) reloj.restart();//Si toca el nivel 1, se reinicia el reloj
		}
		
	}
}

float Juego::verTiempo ( ) {
	return reloj.getElapsedTime().asSeconds();//Devuelve cuantos segundos pasaron desde su inicializacion, dada durante el cambio de
	//escena al nivel 1
}

void Juego::cambiarEscena (Escena *escNueva) {
	escSiguiente=escNueva;//se guarda la escena siguiente para que termine la actual
}

Juego::~Juego ( ) {
	delete escActual;
}

