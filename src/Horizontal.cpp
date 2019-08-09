#include "Horizontal.h"

Horizontal::Horizontal(float X,float Y) : Movil(X,Y,Global::t_horizontal) {
	alcance=4;//inicializa el maximo alcance de la plataforma
}

void Horizontal::actualizar () {
	//La plataforma se desplaza automaticamente. Cuando llega a la distancia maxima, vuelve
	if(signo==1){
		s.move(5,0);
		if(posicion().x-inicio.x==Global::tamanoCuadro*alcance) signo=-1;
	}else{
		s.move(-5,0);
		if(inicio.x-posicion().x==Global::tamanoCuadro*alcance) signo=1;
	}
}

sf::Vector2f Horizontal::seMueve ( ) {
	return sf::Vector2f(signo*5,0);
}

