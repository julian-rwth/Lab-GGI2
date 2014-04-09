#pragma once
#include "aktivesvo.h"
#include <list>

class Weg;
class Fahrzeug;

class Kreuzung :
	public AktivesVO
{
private:
	double p_dTankstelle;
public:
	Kreuzung(string name,double Tank);
	list<Weg*> abgehendeWege;

	void vVerbinde(string hinWeg,string rueckWeg,double laenge,Kreuzung* nachbar);
	void vTanken(Fahrzeug*);
	void vAnnahme(Fahrzeug*, double);
	void vAnnahme(Fahrzeug*);
	void vAbfertigung();
	Weg* ptZufaeligerWeg(Weg*);
	virtual ostream& ostreamAusgabe(ostream& s); 
	istream& istreamEingabe(istream& s);

	virtual ~Kreuzung(void);
};
