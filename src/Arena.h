#ifndef ARENA_H
#define ARENA_H
#include "Suelo.h"
#include "Global.h"
#include "SFML/System.hpp"

class Arena : public Suelo {
public:
	Arena(float X, float Y);
	float rozamiento ( ) override;
	float dureza ( ) override;
	sf::Vector2f seMueve ( ) override;
private:
};

#endif

