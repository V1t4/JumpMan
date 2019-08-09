#ifndef VERTICAL_H
#define VERTICAL_H
#include "Movil.h"
#include "Personaje.h"
#include "Global.h"

class Vertical : public Movil {
public:
	Vertical(float X,float Y);
	void actualizar () override;
	sf::Vector2f seMueve() override;
private:
	float alcance;
};

#endif

