#ifndef PASTO_H
#define PASTO_H
#include "Suelo.h"
#include "Global.h"

class Pasto : public Suelo {
public:
	Pasto(float X, float Y);
	float rozamiento() override;
	float dureza() override;
	sf::Vector2f seMueve() override;
private:
};

#endif
