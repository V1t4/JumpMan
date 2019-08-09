#include "Pasto.h"

Pasto::Pasto(float X, float Y): Suelo(X,Y,Global::t_pasto) {
	
}


float Pasto::rozamiento ( ) {
	return 1;
}

float Pasto::dureza ( ) {
	return 1;
}

sf::Vector2f Pasto::seMueve ( ) {
	return sf::Vector2f(0,0);
}

