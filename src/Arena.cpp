#include "Arena.h"

Arena::Arena (float X, float Y) : Suelo(X,Y,Global::t_arena){
	
}

float Arena::rozamiento ( ) {
	return 5;
}

float Arena::dureza ( ) {
	return -2;
}

sf::Vector2f Arena::seMueve ( ) {
	return sf::Vector2f(0,0);
}

