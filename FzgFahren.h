#pragma once

#include "FzgVerhalten.h"
class Weg;

class FzgFahren :
	public FzgVerhalten
{
public:
	FzgFahren(Weg*);
	double dStrecke(Fahrzeug*,double);
	virtual ~FzgFahren(void);

};
