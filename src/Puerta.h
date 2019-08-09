#ifndef PUERTA_H
#define PUERTA_H
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Puerta {
public:
	Puerta();
	void Ubicar(float x, float y,sf::Texture &t);
	void dibujar(sf::RenderWindow &ventana);
	sf::FloatRect posicionPuerta();
	bool estaUbicada();
private:
	sf::Sprite s;
	
	bool ubicada;
};

#endif

