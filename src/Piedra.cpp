#include "Piedra.h"

Piedra::Piedra(float X, float Y) : Suelo(X,Y,Global::t_piedra) {
	
}

float Piedra::rozamiento ( ) {
	return 1;
}

float Piedra::dureza ( ) {
	return 5;
}

sf::Vector2f Piedra::seMueve ( ) {
	return sf::Vector2f(0,0);
}

