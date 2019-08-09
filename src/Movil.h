#ifndef MOVIL_H
#define MOVIL_H
#include "Suelo.h"
#include <string>
#include <SFML/System.hpp>

using namespace std;

class Movil : public Suelo{
public:
	Movil(float X,float Y,sf::Texture &t);
	virtual void actualizar () = 0;
	virtual sf::Vector2f seMueve() override = 0;
	float rozamiento ( ) override;
	float dureza ( ) override;
protected:
	sf::Vector2f inicio;
	int signo;
};

#endif

