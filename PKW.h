#pragma once
#include "fahrzeug.h"
class Weg;

class PKW :
	public Fahrzeug
{
public:
	double dVerbrauch();
	double dTanken(double dMenge/* =0.0 */);
	void vAbfertigung();
	void vAusgabe();
	double p_dTankinhalt;
	
	PKW(string sName,double dMaxGeschindigkeit,double dVerbrauch, double dTankvolumen=55);
	PKW();
	~PKW(void);
	ostream& ostreamAusgabe(ostream& s); 
	istream& istreamEingabe(istream& s);
	 virtual PKW& operator = (PKW &p);
	 virtual PKW& operator = (Fahrzeug &p);
	 virtual void vZeichnen(Weg* w);
	 virtual double getTankinhalt();

private:
	double p_dVerbrauch;
	double p_dTankvolumen;
};
