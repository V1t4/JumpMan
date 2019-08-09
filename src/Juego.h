#ifndef JUEGO_H
#define JUEGO_H
#include "Escena.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Escena;

class Juego {
public:
	Juego();
	~Juego();
	void correr();
	void cambiarEscena(Escena *escNueva);
	float verTiempo();
private:
	sf::RenderWindow ventana;//Ventana del Juego
	
	Escena *escActual, *escSiguiente;
	
	sf::Clock reloj;
	
};

#endif

