#include "Movil.h"

Movil::Movil(float X,float Y,sf::Texture &t) : Suelo(X,Y,t){
	inicio.x=X;
	inicio.y=Y;
	signo=1;
}

float Movil::rozamiento ( ) {
	return 1;
}

float Movil::dureza ( ) {
	return 1;
}

