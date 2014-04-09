#pragma once
#include "fahrzeug.h"
class Weg;

class Fahrrad :
	public Fahrzeug
{
public:
	Fahrrad(void);
	~Fahrrad(void);
	Fahrrad(string sName);
	Fahrrad(string sName,double dMaxGeschindigkeit);
	double dGeschwindigkeit();
	void vAusgabe();
	ostream& ostreamAusgabe(ostream& s); 
	istream& istreamEingabe(istream& s);
	virtual void vZeichnen(Weg* w);
};
