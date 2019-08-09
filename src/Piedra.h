#ifndef PIEDRA_H
#define PIEDRA_H
#include "Suelo.h"
#include "Global.h"

class Piedra : public Suelo {
public:
	Piedra(float X, float Y);
	float rozamiento ( ) override;
	float dureza ( ) override;
	sf::Vector2f seMueve ( ) override;
private:
};

#endif

