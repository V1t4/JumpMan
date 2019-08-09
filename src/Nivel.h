#ifndef Nivel_H
#define Nivel_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Global.h"
#include "Personaje.h"
#include "Enemigo.h"
#include "Puerta.h"
#include "Llave.h"
#include "Escena.h"
#include "Final.h"
#include "GameOver.h"
#include "Suelo.h"
#include "Pasto.h"
#include "Arena.h"
#include "Vertical.h"
#include "Horizontal.h"
#include "Hielo.h"
#include "Piedra.h"

class Nivel : public Escena {
public:
	Nivel();
	void actualizar (Juego &j) override;
	void dibujar(sf::RenderWindow &ventana);
	~Nivel();
private:
	
	sf::View camara;//Camara del Nivel
	sf::Vector2f posicionCamara;
	void moverCamara();
	
	Personaje p;//Personaje del Nivel
	std::vector <Suelo*> Su;//Vector con distintos tipos de suelo, creados con polimorfismo
	std::vector <Llave*> Ll;
	std::vector <Enemigo*> En;
	Puerta puerta;
	
	sf::Text texto;
	void actualizarTexto(float tiempo);
	
	void cargarNivel(string archBin);
};

#endif
