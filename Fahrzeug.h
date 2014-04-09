#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include "AktivesVO.h"

using namespace std;

class FzgVerhalten;
class Weg;

class Fahrzeug : public AktivesVO
{

protected:
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dAbschnittStrecke;
	FzgVerhalten* p_ptVerhalten;
	

private:
	void vInitialisierung();

public:
	Fahrzeug(void);
	Fahrzeug(string sName);
	Fahrzeug(string sName,double dMaxGeschindigkeit);

	
	virtual	double dTanken(double dMenge=0.0);
	virtual ~Fahrzeug(void);
	virtual double dGeschwindigkeit();
	virtual void vAbfertigung();
	virtual void vAusgabe();
	virtual ostream& ostreamAusgabe(ostream& s);
	virtual Fahrzeug& operator = (Fahrzeug &f);
	virtual void vZeichnen(Weg*);
	virtual double getTankinhalt();
	
	void vNeueStrecke(Weg*);
	void vNeueStrecke(Weg* w,double start);

	FzgVerhalten* GetFzgVerhalten(){return p_ptVerhalten;};
	double GetdAbschnittStrecke(){return p_dAbschnittStrecke;};

	bool operator < (Fahrzeug f);
};




