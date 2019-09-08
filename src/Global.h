#ifndef GLOBAL_H
#define GLOBAL_H
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include "SFML/Graphics.hpp"

class Texture;
class Font;

//struct linea{
//	std::string texto;
//	unsigned int tamanio;
//	float x,y;
//};

class Global{
public:
	Global();
	static int cantNiv;
	static int nivActual;
	static float anchoVentana;
	static float altoVentana;
	static float anchoMundo;
	static float altoMundo;
	static float tamanoCuadro;
	static float tiempoJugador;
	
	static std::string jugador;
	static sf::Texture t_margen;
	static sf::Texture t_pasto;
	static sf::Texture t_arena;
	static sf::Texture t_piedra;
	static sf::Texture t_hielo;
	static sf::Texture t_horizontal;
	static sf::Texture t_vertical;
	static sf::Texture t_enemigo;
	static sf::Texture t_llave;
	static sf::Texture t_puerta;
	static sf::Texture t_personaje;
	
	static sf::Font fuente;
	
	static std::vector<sf::Text> txt_menu;
	static std::vector<sf::Text> txt_instrucciones;
	static std::vector<sf::Text> txt_verTiempos;
	static std::vector<sf::Text> txt_creditos;
	static std::vector<sf::Text> txt_final;
	static std::vector<sf::Text> txt_gameOver;

	static void CargarTexturas();
	static void CargarTextos(std::string idioma);
	static std::vector<sf::Text> LeerArchivo(std::string archivo);
private:
};

#endif

