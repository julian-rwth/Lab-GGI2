#include "Streckenende.h"
#include "Weg.h"
#include "Fahrzeug.h"
extern double dGlobaleZeit;
Streckenende::Streckenende(Fahrzeug* f,Weg* w):FahrAusnahme(f,w)
{
}

Streckenende::~Streckenende(void)
{
}
void Streckenende::vBearbeiten()
{
	Weg* neu = this->p_ptWeg->wegNach->ptZufaeligerWeg(this->p_ptWeg);
	cout<<"Exception: Streckenende. Ausgeloest von Farzeug: "<<p_ptFahrzeug->p_sName<<" auf Weg: "<<p_ptWeg->p_sName<<"\n\n";
	cout<<"Setze um.\nZeit: "<<dGlobaleZeit<<"\nKreuzung: "<<this->p_ptWeg->wegNach->p_sName<<"\nWechsel: "<<this->p_ptWeg->p_sName<<" -> "<<neu->p_sName<<"\nFahrzeug: "<<*this->p_ptFahrzeug<<"\n\n";
	
	this->p_ptWeg->vAbgabe(this->p_ptFahrzeug);
	this->p_ptWeg->wegNach->vTanken(this->p_ptFahrzeug);
	neu->vAnnahme(this->p_ptFahrzeug);
	
	
}