#include "Fahrzeug.h"
#include "Weg.h"
#include "FzgFahren.h"
#include "FzgParken.h"

using namespace std;

extern double dGlobaleZeit;


Fahrzeug::Fahrzeug()
{
	this->vInitialisierung();
}

Fahrzeug::Fahrzeug(string sName):AktivesVO(sName)
{
	this->vInitialisierung();
}

Fahrzeug::Fahrzeug( string sName,double dMaxGeschindigkeit ):AktivesVO(sName)
{
	this->vInitialisierung();
	this->p_dMaxGeschwindigkeit = dMaxGeschindigkeit;
}

Fahrzeug::~Fahrzeug(void)
{

}
void Fahrzeug::vZeichnen(Weg* w)
{

}

void Fahrzeug::vInitialisierung()
{
	this->p_dGesamtStrecke=0;
	this->p_dGesamtZeit=0;
	this->p_dMaxGeschwindigkeit=0;
	this->p_dZeit=0;
	this->p_dAbschnittStrecke = 0;
	this->p_ptVerhalten = 0;
}

void Fahrzeug::vAbfertigung()
{
	if(this->p_dZeit != dGlobaleZeit)
	{
			
			double timeRecover = this->p_dZeit;
			this->p_dZeit = dGlobaleZeit;
			double gefahreneStrecke = this->p_ptVerhalten->dStrecke(this,(dGlobaleZeit - timeRecover));
			this->p_dGesamtStrecke += gefahreneStrecke;
			this->p_dAbschnittStrecke += gefahreneStrecke;
	}
	this->p_dZeit = dGlobaleZeit;
}

double Fahrzeug::dTanken( double dMenge/*=0.0*/ )
{
	return 0.0;
}

double Fahrzeug::dGeschwindigkeit()
{
	return this->p_dMaxGeschwindigkeit;
}
double Fahrzeug::getTankinhalt()
{
	return -1;
}

ostream& Fahrzeug::ostreamAusgabe(ostream& s)
{
	return (( AktivesVO::ostreamAusgabe(s) )<<this->p_dMaxGeschwindigkeit<<"\t"<<this->p_dGesamtStrecke<<"\t"<<this->p_dAbschnittStrecke);
}

void Fahrzeug::vAusgabe()
{
	cout<<this->p_iID<<"\t"<<this->p_sName<<"\t:\t"<<this->p_dMaxGeschwindigkeit<<"\t"<<this->p_dGesamtStrecke<<"\t"<<this->p_dAbschnittStrecke;
}

void Fahrzeug::vNeueStrecke(Weg* w)
{
	if(this->p_ptVerhalten!=0)
	{
		delete this->p_ptVerhalten;
	}
	FzgFahren* fz = new FzgFahren(w);
	this->p_ptVerhalten = fz;
	this->p_dAbschnittStrecke=0;
}

void Fahrzeug::vNeueStrecke(Weg* w,double start)
{
	if(this->p_ptVerhalten!=0)
	{
		delete this->p_ptVerhalten;
	}
	FzgParken* fz = new FzgParken(w,start);
	this->p_ptVerhalten = fz;
	this->p_dAbschnittStrecke=0;
}

bool Fahrzeug::operator < (Fahrzeug f)
{
	if(f.p_dGesamtStrecke>=this->p_dGesamtStrecke)
		return true;
	else
		return false;
}


Fahrzeug& Fahrzeug::operator = (Fahrzeug& f)
{
	this->p_dGesamtStrecke = f.p_dGesamtStrecke;
	this->p_dGesamtZeit = f.p_dGesamtZeit;
	this->p_dMaxGeschwindigkeit = f.p_dMaxGeschwindigkeit;
	this->p_dZeit = f.p_dZeit;
	this->p_sName = f.p_sName;
	
	return *this;
}