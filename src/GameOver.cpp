#include "GameOver.h"

GameOver::GameOver() {
	
	//Se inicializan los textos
	titulo.setFont(Global::fuente);
	titulo.setColor(sf::Color::White);
	titulo.setString("JUEGO TERMINADO!");
	titulo.setCharacterSize(120);
	titulo.setPosition(sf::Vector2f((Global::anchoVentana-titulo.getLocalBounds().width)/2.0, 50));
	presioneTecla1.setFont(Global::fuente);
	presioneTecla1.setColor(sf::Color::White);
	presioneTecla1.setString("Presione ENTER para volver a jugar");
	presioneTecla1.setCharacterSize(40);
	presioneTecla1.setPosition(sf::Vector2f((Global::anchoVentana-presioneTecla1.getLocalBounds().width)/2.0, 500));
	presioneTecla2.setFont(Global::fuente);
	presioneTecla2.setColor(sf::Color::White);
	presioneTecla2.setString("Presione SPACE para volver al menu");
	presioneTecla2.setCharacterSize(40);
	presioneTecla2.setPosition(sf::Vector2f((Global::anchoVentana-presioneTecla2.getLocalBounds().width)/2.0, 550));
	
	//Se agrega un margen
	margen.setTexture(Global::t_margen);
	
	//Se inicia el indicador de que no se solto space
	soltoTecla = false;
}

void GameOver::dibujar (sf::RenderWindow & ventana) {
	ventana.clear(sf::Color::Red);
	ventana.draw(margen);
	ventana.draw(titulo);
	ventana.draw(presioneTecla1);
	ventana.draw(presioneTecla2);
}

void GameOver::actualizar (Juego &j) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){//Si se presiona enter, se vuelve a empezar
		Global::nivActual=1;
		j.cambiarEscena(new Nivel());
	}
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) soltoTecla = true;
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space))&&(soltoTecla))j.cambiarEscena(new Menu());//Con space, se vuelve al menu
}
