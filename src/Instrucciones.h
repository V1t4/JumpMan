#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H
#include "Escena.h"
#include "SFML/Graphics.hpp"
#include "Global.h"
#include "SFML/Window.hpp"
#include "Nivel.h"
#include "Menu.h"

class Instrucciones : public Escena {
public:
	Instrucciones();
	void actualizar (Juego & j);
	void dibujar (sf::RenderWindow & ventana);
private:
	sf::Sprite margen;
};

#endif

