#ifndef FINAL_H
#define FINAL_H
#include "Escena.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Global.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include "Menu.h"
#include "Nivel.h"
#include "VerTiempos.h"
#include "InputBox.h"

class Final : public Escena {
public:
	Final();
	void dibujar (sf::RenderWindow & ventana) override;
	void actualizar (Juego &j) override;
	void procesarEvento (const sf::Event & evento) override;
private:
	sf::Text titulo;
	InputText nombre;
	sf::Sprite margen;
	
	void guardarTiempo();
};

#endif

