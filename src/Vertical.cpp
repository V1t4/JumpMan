#include "Vertical.h"

Vertical::Vertical(float X,float Y) : Movil(X,Y,Global::t_vertical){ alcance=4; }

void Vertical::actualizar () {
	if(signo==1){
		s.move(0,5);
		if(posicion().y-inicio.y==alcance*Global::tamanoCuadro) signo=-1;
	}else{
		s.move(0,-5);
		if(inicio.y-posicion().y==alcance*Global::tamanoCuadro) signo=1;
	}
}

sf::Vector2f Vertical::seMueve ( ) {
	return sf::Vector2f(0,signo*5);
}

