#include "Losfahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
Losfahren::Losfahren(Fahrzeug* f,Weg* w):FahrAusnahme(f,w)
{
}

Losfahren::~Losfahren(void)
{
}
void Losfahren::vBearbeiten()
{
	this->p_ptWeg->vAbgabe(this->p_ptFahrzeug);
	this->p_ptWeg->vAnnahme(this->p_ptFahrzeug); 
	cout<<"Exception: Losfahren. Ausgeloest von Farzeug: "<<p_ptFahrzeug->p_sName<<" auf Weg: "<<p_ptWeg->p_sName<<"\n\n";
}