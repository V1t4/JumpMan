#include "Llave.h"

Llave::Llave(float x, float y,sf::Texture &t) {
	s.setPosition (x,y);//Se ubica la llave
	s.setTexture(t);//Se carga su textura
	borrada = false;//Se le atribuye un booleano para saber si hay que dibujar o no
}

void Llave::dibujar (sf::RenderWindow &ventana) {
	ventana.draw(s);
}

void Llave::actualizar (Personaje &per) {
	//Si el personaje intersecta la llave y esta no esta dibujada, no pasa nada pues ya la tomo.
	//Si no, el personaje la recoje y la llave desaparece
	if((s.getGlobalBounds().intersects(per.posicionPersonaje()))&&(!borrada)){
		borrada = true;
		per.tomarLlave();
	}
}

bool Llave::eliminada ( ) {
	return borrada;
}

