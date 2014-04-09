#pragma once

#include<iostream>
#include<list>
#include"AktivesVO.h"
#include"LazyListe.h"
#include"Kreuzung.h" 

class Fahrzeug;

using namespace std;

class Weg : public AktivesVO
{
private:
	double p_dLaenge;


public:
	Weg(void);
	Weg(string name,double laenge);
	virtual ~Weg(void);

	Kreuzung* wegNach;
	Weg* rueckweg;

	void vAnnahme(Fahrzeug*);
	void vAnnahme(Fahrzeug*,double);
	void vAbfertigung();
	double Getp_dLaenge(){return p_dLaenge;};
	LazyListe<Fahrzeug*> p_ptFahrzeuge;
	virtual ostream& ostreamAusgabe(ostream& s); 
	void vAbgabe(Fahrzeug*);
};
