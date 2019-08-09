#include "Menu.h"

Menu::Menu() {
	titulo.setFont(Global::fuente);
	titulo.setColor(sf::Color::White);
	titulo.setString("JumpMan!");
	titulo.setCharacterSize(200);
	titulo.setPosition(sf::Vector2f((Global::anchoVentana-titulo.getLocalBounds().width)/2.0, 20));
	
	//Se inicializan los textos
	presioneTecla1.setFont(Global::fuente);
	presioneTecla1.setColor(sf::Color::White);
	presioneTecla1.setString("Presione ENTER para empezar");
	presioneTecla1.setCharacterSize(40);
	presioneTecla1.setPosition(sf::Vector2f((Global::anchoVentana-presioneTecla1.getLocalBounds().width)/4-50, 450));
	presioneTecla2.setFont(Global::fuente);
	presioneTecla2.setColor(sf::Color::White);
	presioneTecla2.setString("Presione SPACE para los creditos");
	presioneTecla2.setCharacterSize(40);
	presioneTecla2.setPosition(sf::Vector2f((Global::anchoVentana-presioneTecla2.getLocalBounds().width)/4-50, 575));
	presioneTecla3.setFont(Global::fuente);
	presioneTecla3.setColor(sf::Color::White);
	presioneTecla3.setString("Presione TAB para ver mejores tiempos");
	presioneTecla3.setCharacterSize(40);
	presioneTecla3.setPosition(sf::Vector2f(3*(Global::anchoVentana-presioneTecla3.getLocalBounds().width)/4+50, 575));
	presioneTecla4.setFont(Global::fuente);
	presioneTecla4.setColor(sf::Color::White);
	presioneTecla4.setString("Presione H para ver como jugar");
	presioneTecla4.setCharacterSize(40);
	presioneTecla4.setPosition(sf::Vector2f(3*(Global::anchoVentana-presioneTecla4.getLocalBounds().width)/4+25, 450));
	
	//Se agrega un margen
	margen.setTexture(Global::t_margen);
	
	//Booleanos para asegurarse de que el usuario suelta las teclas enter y space respectivamente
	SoltoTecla1=false;
	SoltoTecla2=false;
}

void Menu::actualizar (Juego &j) {
	
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) SoltoTecla1=true;
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) SoltoTecla2=true;
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)&&SoltoTecla1) {//Con enter se inicia un juego
		Global::nivActual=1;
		j.cambiarEscena(new Nivel());
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&SoltoTecla2)//Con space se ven los creditos
		j.cambiarEscena(new Creditos());
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))//Con tab se ven los mejores tiempos
		j.cambiarEscena(new VerTiempos());
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::H))//Con h se ven las instrucciones
		j.cambiarEscena(new Instrucciones());
	
}

void Menu::dibujar (sf::RenderWindow & ventana) {
	ventana.clear(sf::Color::Blue);
	ventana.draw(margen);
	ventana.draw(titulo);
	ventana.draw(presioneTecla1);
	ventana.draw(presioneTecla2);
	ventana.draw(presioneTecla3);
	ventana.draw(presioneTecla4);
}

