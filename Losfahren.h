#pragma once
#include "fahrausnahme.h"
class Fahrzeug;

class Losfahren :
	public FahrAusnahme
{
public:
	Losfahren(Fahrzeug*,Weg*);
	virtual ~Losfahren(void);
	virtual void vBearbeiten();
};
