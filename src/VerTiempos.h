#ifndef VERTIEMPOS_H
#define VERTIEMPOS_H
#include "Escena.h"
#include "Global.h"
#include <SFML/Window.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "Menu.h"

class VerTiempos : public Escena {
public:
	VerTiempos();
	void procesarEvento (const sf::Event & evento) override;
	void actualizar (Juego & j) override;
	void dibujar (sf::RenderWindow & ventana) override;
private:
	sf::Sprite margen;
	
	sf::Text titulo;
	sf::Text presioneTecla1;
	sf::Text presioneTecla2;
	sf::Text tablaTiempos;
	
	void cargarTiempos();
	void borrarTiempos();
};

#endif

