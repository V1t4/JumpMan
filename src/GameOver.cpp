#include "GameOver.h"

GameOver::GameOver() {
	//Se agrega un margen
	margen.setTexture(Global::t_margen);
	
	//Se inicia el indicador de que no se solto space
	soltoTecla = false;
}

void GameOver::dibujar (sf::RenderWindow & ventana) {
	ventana.clear(sf::Color::Red);
	ventana.draw(margen);
	for (sf::Text linea : Global::txt_gameOver)
		ventana.draw(linea);
	
}

void GameOver::actualizar (Juego &j) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){//Si se presiona enter, se vuelve a empezar
		Global::nivActual=1;
		j.cambiarEscena(new Nivel());
	}
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) soltoTecla = true;
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space))&&(soltoTecla))j.cambiarEscena(new Menu());//Con space, se vuelve al menu
}
