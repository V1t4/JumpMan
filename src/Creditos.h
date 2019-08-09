#ifndef CREDITOS_H
#define CREDITOS_H
#include "Escena.h"
#include <SFML/Graphics.hpp>
#include "Global.h"
#include <SFML/Window.hpp>
#include "Menu.h"

class Creditos : public Escena {
public:
	Creditos();
	void actualizar (Juego &j) override;
	void dibujar (sf::RenderWindow & ventana) override;
private:
	sf::Text titulo1;
	sf::Text titulo2;
	sf::Text presioneTecla;
	
	sf::Sprite margen;
};

#endif

