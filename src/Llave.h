#ifndef LLAVE_H
#define LLAVE_H
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Personaje.h"

class Llave {
public:
	Llave(float x, float y,sf::Texture &t);
	void dibujar(sf::RenderWindow &ventana);
	void actualizar(Personaje &per);
	bool eliminada();
private:
	sf::Sprite s;
	bool borrada;
};

#endif

