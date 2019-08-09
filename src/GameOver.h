#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "Escena.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Global.h"
#include "Menu.h"
#include "Nivel.h"

class GameOver : public Escena {
public:
	GameOver();
	void actualizar(Juego &j) override;
	void dibujar (sf::RenderWindow & ventana) override;
private:
	sf::Sprite margen;
	
	sf::Text titulo;
	sf::Text presioneTecla1;
	sf::Text presioneTecla2;
	
	bool soltoTecla;
};

#endif

