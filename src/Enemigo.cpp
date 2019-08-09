#include "Enemigo.h"

Enemigo::Enemigo (float x, float y,sf::Texture &t) {
	//Se ubica al enemigo en su posicion inicial, se inicializa el signo del desplazamiento en 1 y su
	//alcance en 3, para que llegue hasta 3 celdas de distancia del inicio
	s.setPosition (sf::Vector2f(x,y));
	s.setTexture(t);
	inicio=x;
	alcance=3;
	signo=1;
}

void Enemigo::actualizar ( ) {
	//El enemigo se desplaza automaticamente. Cuando llega a la distancia maxima, vuelve
	if(signo==1){
		s.move(5,0);
		if(s.getPosition().x-inicio==alcance*Global::tamanoCuadro) {
			signo=-1;
			s.setScale(-1,1);
		}
	}else{
		s.move(-5,0);
		if(inicio-s.getPosition().x==alcance*Global::tamanoCuadro) {
			signo=1;
			s.setScale(1,1);
		}
	}
}

sf::FloatRect Enemigo::posicionEnemigo ( ) {
	//Retorna un rectangulo con la posicion del enemigo
	return s.getGlobalBounds();
}

void Enemigo::dibujar (sf::RenderWindow & ventana) {
	ventana.draw(s);
}

