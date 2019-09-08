#ifndef PERSONAJE_H
#define PERSONAJE_H
#include "SFML/Graphics.hpp"
#include "Vertical.h"
#include <vector>
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include "Global.h"

enum lado {derecha, izquierda, arriba, abajo};

class Personaje {
public:
	Personaje();
	void inicializar(sf::Texture &t);
	void dibujar(sf::RenderWindow &ventana);
	void actualizar(std::vector <Suelo*> &Su);
	sf::FloatRect posicionPersonaje();
	int llavesActuales();
	void tomarLlave();
private:
	//Textura y sprite del personaje
	sf::Sprite sp;
	
	//Auxiliares para la animacion del sprite del personaje
	int direccion;
	int estado;
	int cambioEstado;
	void actualizarSprite();
	
	//Auxiliares para el salto
	int caida;
	int tiempoCayendo;
	bool estaSaltando;
	int maxSalto;
	int alturaSaltada;
	void saltar(std::vector <Suelo*> &Su);
	float determinarAlturaMaxima(std::vector<Suelo*> & Su); 
	
	//Auxiliares para el movimiento
	bool estaParado;
	void moverse(lado l,std::vector <Suelo*> &Su);
	float rozamiento(std::vector <Suelo*> &Su);
	bool TocaSuelo(std::vector <Suelo*> &Su,lado l);
	sf::Vector2f seMueveSuelo(std::vector <Suelo*> &Su);
	
	//Cuenta de las llaves poseidas
	int nroLlaves;
};
#endif
