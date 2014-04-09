#include "FahrAusnahme.h"

FahrAusnahme::FahrAusnahme(Fahrzeug* f,Weg* w)
{
	this->p_ptFahrzeug=f;
	this->p_ptWeg=w;
}

FahrAusnahme::~FahrAusnahme(void)
{
}
