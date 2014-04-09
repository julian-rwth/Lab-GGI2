#pragma once
#include "fahrausnahme.h"

class Streckenende :
	public FahrAusnahme
{
public:
	Streckenende(Fahrzeug*,Weg*);
	virtual ~Streckenende(void);
	virtual void vBearbeiten();
};
