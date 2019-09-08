#ifndef HORIZONTAL_H
#define HORIZONTAL_H
#include "Movil.h"
#include "Personaje.h"
#include "Global.h"
#include "SFML/System.hpp"

class Horizontal : public Movil {
public:
	Horizontal(float X, float Y);
	void actualizar () override;
	sf::Vector2f seMueve() override;
private:
	float alcance;
};

#endif

