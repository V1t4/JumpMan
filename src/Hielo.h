#ifndef HIELO_H
#define HIELO_H
#include "Suelo.h"
#include "Global.h"
#include <SFML/System.hpp>

class Hielo : public Suelo {
public:
	Hielo(float X, float Y);
	float rozamiento ( ) override;
	float dureza ( ) override;
	sf::Vector2f seMueve ( ) override;
private:
};

#endif

