#include "Instrucciones.h"

Instrucciones::Instrucciones() {
	
	//Se inicializan los textos
	titulo.setFont(Global::fuente);
	titulo.setColor(sf::Color::White);
	titulo.setString("Use las flechas izquierda y derecha, o las teclas 'A' y 'D', para moverse\ny arriba, 'W' o espacio para saltar.\n\nRecoja todas las llaves y vaya a la puerta para pasar de nivel.\n \nEvite a los enemigos y no caiga al vacio ");
	titulo.setCharacterSize(60);
	titulo.setPosition(sf::Vector2f(60, 60));
	presioneTecla1.setFont(Global::fuente);
	presioneTecla1.setColor(sf::Color::White);
	presioneTecla1.setString("Presione ENTER para jugar");
	presioneTecla1.setCharacterSize(40);
	presioneTecla1.setPosition(sf::Vector2f(60, 580));
	presioneTecla2.setFont(Global::fuente);
	presioneTecla2.setColor(sf::Color::White);
	presioneTecla2.setString("Presione SPACE para volver al menu");
	presioneTecla2.setCharacterSize(40);
	presioneTecla2.setPosition(sf::Vector2f(Global::anchoVentana-presioneTecla2.getLocalBounds().width-60, 580));
	
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
	ventana.draw(titulo);
	ventana.draw(presioneTecla1);
	ventana.draw(presioneTecla2);
	ventana.display();
}

