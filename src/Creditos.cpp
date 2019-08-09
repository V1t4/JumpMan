#include "Creditos.h"

Creditos::Creditos() {
	
	//Se inicializan los textos a mostrar
	titulo1.setFont(Global::fuente);
	titulo1.setColor(sf::Color::White);
	titulo1.setString("Este juego fue hecho por Rosario Vitale para la materia \nProgramacion Orientada a Objetos, carrera Ingenieria en Informatica, \nUniversidad Nacional del Litoral");
	titulo1.setCharacterSize(60);
	titulo1.setPosition(sf::Vector2f(80, 100));
	titulo2.setFont(Global::fuente);
	titulo2.setColor(sf::Color::White);
	titulo2.setString("Diciembre 2018");
	titulo2.setCharacterSize(40);
	titulo2.setPosition(sf::Vector2f(80, 350));
	presioneTecla.setFont(Global::fuente);
	presioneTecla.setColor(sf::Color::White);
	presioneTecla.setString("Presione ENTER para volver al menu");
	presioneTecla.setCharacterSize(40);
	presioneTecla.setPosition(sf::Vector2f((Global::anchoVentana-presioneTecla.getLocalBounds().width)-150, 550));
	
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
	ventana.draw(titulo1);
	ventana.draw(titulo2);
	ventana.draw(presioneTecla);
	ventana.display();
}

