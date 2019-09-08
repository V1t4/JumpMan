#include "Menu.h"

Menu::Menu() {
	titulo.setFont(Global::fuente);
	titulo.setColor(sf::Color::White);
	titulo.setString("JumpMan!");
	titulo.setCharacterSize(200);
	titulo.setPosition(sf::Vector2f((Global::anchoVentana-titulo.getLocalBounds().width)/2.0, 20));
	
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
	
	for (sf::Text linea : Global::txt_menu)
		ventana.draw(linea);
}

