#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Global.h"
#include <SFML/Graphics.hpp>

class Enemigo {
public:
	Enemigo(float x, float y,sf::Texture &t);
	void actualizar();
	void dibujar(sf::RenderWindow &ventana);
	sf::FloatRect posicionEnemigo();
private:
	float inicio;
	int alcance;
	int signo;
	sf::Sprite s;
};

#endif

