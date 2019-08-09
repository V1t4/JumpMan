#include "Puerta.h"

Puerta::Puerta () {
	ubicada = false;//Por defecto, la puerta no esta ubicada
}
void Puerta::Ubicar(float x, float y,sf::Texture &t) {
	//Se ubica la puerta en su lugar y se le asigna la textura
	s.setTexture(t);
	s.setPosition (x,y);
	
	ubicada = true;
}

void Puerta::dibujar (sf::RenderWindow & ventana) {
	ventana.draw(s);
}

sf::FloatRect Puerta::posicionPuerta ( ) {
	//Devuelve un rectangulo con la posicion ocupada por la puerta
	return s.getGlobalBounds();
}

bool Puerta::estaUbicada ( ) {
	//Determina si la puerta fue ubicada
	return ubicada;
}

