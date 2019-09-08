#ifndef SUELO_H
#define SUELO_H
#include "SFML/Graphics.hpp"

class Suelo {
public:
	
	Suelo(float X, float Y, sf::Texture &t);
	
	virtual void actualizar();//Metodo virtual ya que los distintos tipos de suelo pueden tener
	//distintos comportamientos
	
	//Metodos virtuales puros, implementados obligatoriamente por las hijas
	virtual float rozamiento() = 0;
	virtual float dureza() = 0;
	virtual sf::Vector2f seMueve() = 0;
	
	//Metodos no virtuales ya que no dependen del tipo de Suelo
	void dibujar(sf::RenderWindow &ventana);
	sf::FloatRect posicionSuelo();
	sf::Vector2f posicion();
	
	virtual ~Suelo(); //Destructor virtual por las dudas
private:
protected://Protegidos para que las hijas puedan modificarlo
	//Sprite del suelo
	sf::Sprite s;
	
};
#endif
