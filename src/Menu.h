#ifndef MENU_H
#define MENU_H
#include "Escena.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Global.h"
#include <string>
#include "Nivel.h"
#include "Creditos.h"
#include "VerTiempos.h"
#include "Instrucciones.h"

class Menu : public Escena {
public:
	Menu();
	void actualizar (Juego &j) override;
	void dibujar(sf::RenderWindow &ventana) override;
private:
	sf::Sprite margen;
	sf::Text titulo;
	sf::Text presioneTecla1;
	sf::Text presioneTecla2;
	sf::Text presioneTecla3;
	sf::Text presioneTecla4;
	bool SoltoTecla1;
	bool SoltoTecla2;
};

#endif


