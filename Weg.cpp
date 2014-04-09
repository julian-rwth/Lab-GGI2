#include "Weg.h"
#include "Fahrzeug.h"
#include "Fahrausnahme.h"

Weg::Weg(void)
{

}
Weg::Weg(string name,double laenge):AktivesVO(name)
{
	this->p_dLaenge = laenge;
	AktivesVO::objekte->insert(pair<string,AktivesVO*>(name,this));
}

void Weg::vAbfertigung()
{
	list<Fahrzeug*>::iterator it = this->p_ptFahrzeuge.begin();
	while(it != this->p_ptFahrzeuge.end())
	{
		try
		{
			(*it)->vAbfertigung();
			(*it)->vZeichnen(this);
		}catch(FahrAusnahme* ex)
		{
			ex->vBearbeiten();
		}
		it++;
	}
	p_ptFahrzeuge.vAktualisieren();

}

ostream& Weg::ostreamAusgabe(ostream& s)
{
	AktivesVO::ostreamAusgabe(s)<<"\t"<<this->p_dLaenge<<"( ";
	list<Fahrzeug*>::iterator it = this->p_ptFahrzeuge.begin();
	while(it != this->p_ptFahrzeuge.end())
	{
		s<<(*it)->p_sName<<" ";
		it++;
	}
	s<<")\t";
	return s;
}

void Weg::vAnnahme(Fahrzeug* f)
{
	f->vNeueStrecke(this);
	this->p_ptFahrzeuge.push_back(f);
}
void Weg::vAnnahme(Fahrzeug* f,double start)
{
	f->vNeueStrecke(this,start);
	this->p_ptFahrzeuge.push_front(f);
}

void Weg::vAbgabe(Fahrzeug* f)
{
	list<Fahrzeug*>::iterator it = this->p_ptFahrzeuge.begin();
	while(it!=this->p_ptFahrzeuge.end())
	{
		if(*it==f)
		{
			this->p_ptFahrzeuge.erase(it);
		}
		it++;
	}

}

Weg::~Weg(void)
{
}
