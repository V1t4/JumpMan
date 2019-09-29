#include "Creditos.h"

Creditos::Creditos() {
	
	//Se agrega un margen
	margen.setTexture(Global::t_margen);
	
}

void Creditos::actualizar (Juego &j) {
	//Si se apreta enter, vuelve al menu
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) j.cambiarEscena(new Menu());
}

void Creditos::dibujar (sf::RenderWindow & ventana) {
	ventana.clear(sf::Color(200,50,0));
	ventana.draw(margen);
	
	for (sf::Text linea : Global::txt_creditos)
		ventana.draw(linea);
	
	ventana.display();
}

