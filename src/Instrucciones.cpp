#include "Instrucciones.h"

Instrucciones::Instrucciones() {
	//Se agrega un margen
	margen.setTexture(Global::t_margen);
}

void Instrucciones::actualizar (Juego & j) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){//Con enter se inicia un nivel
		Global::nivActual=1;
		j.cambiarEscena(new Nivel());
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) j.cambiarEscena(new Menu());//Con space se vuelve al menu
}

void Instrucciones::dibujar (sf::RenderWindow & ventana) {
	ventana.clear(sf::Color(0,127,0));
	ventana.draw(margen);
	
	for (sf::Text linea : Global::txt_instrucciones)
		ventana.draw(linea);
	
	ventana.display();
}

