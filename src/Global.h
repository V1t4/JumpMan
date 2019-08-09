#ifndef GLOBAL_H
#define GLOBAL_H
#include <string>
#include <SFML/Graphics.hpp>

class Texture;
class Font;

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
	
	static void CargarTexturas();
private:
};

#endif

