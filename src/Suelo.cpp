#include "Suelo.h"

Suelo::Suelo (float X, float Y, sf::Texture &t) {
	s.setTexture(t);
	
	//Ubico al suelo en su posicion inicial
	s.setPosition (sf::Vector2f(X,Y));
	
}

sf::FloatRect Suelo::posicionSuelo ( ) {
	//Devuelvo la posicion ocupada por el suelo
	return s.getGlobalBounds();
}

void Suelo::dibujar (sf::RenderWindow & ventana) {
	ventana.draw(s);
}

void Suelo::actualizar () { }//Por defecto, el suelo no hace nada. Puede cambiar dependiendo
//del tipo de suelo

sf::Vector2f Suelo::posicion ( ) {
	return s.getPosition();
}

Suelo::~Suelo ( ) { }
