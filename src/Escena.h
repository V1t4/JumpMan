#ifndef ESCENA_H
#define ESCENA_H
#include "Juego.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Juego;

class Escena {
public:
	Escena();
	virtual void actualizar(Juego &j)=0;
	virtual void dibujar(sf::RenderWindow &ventana)=0;
	virtual void procesarEvento(const sf::Event &evento);
	virtual ~Escena();
private:
};

#endif

