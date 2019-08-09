#include "Hielo.h"

Hielo::Hielo(float X, float Y) : Suelo(X,Y,Global::t_hielo){
	
}

float Hielo::rozamiento ( ) {
	return -20;
}

float Hielo::dureza ( ) {
	return 3;
}

sf::Vector2f Hielo::seMueve ( ) {
	return sf::Vector2f(0,0);
}

