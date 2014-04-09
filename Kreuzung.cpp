#include "Kreuzung.h"
#include "Weg.h"
#include "Fahrzeug.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Kreuzung::Kreuzung(string name,double tank):AktivesVO(name)
{
	this->p_dTankstelle=tank;
}

void Kreuzung::vVerbinde(string hinWeg,string rueckWeg,double laenge,Kreuzung* nachbar)
{
	Weg* hin = new Weg(hinWeg,laenge);
	Weg* rueck = new Weg(rueckWeg,laenge);
	hin->rueckweg = rueck;
	rueck->rueckweg = hin;
	hin->wegNach = this;
	rueck->wegNach = nachbar;
	this->abgehendeWege.push_back(rueck);
	nachbar->abgehendeWege.push_back(hin);
}
void Kreuzung::vTanken(Fahrzeug* f)
{
	if(this->p_dTankstelle>0)
	{
		this->p_dTankstelle-=f->dTanken();
	}
}
void Kreuzung::vAnnahme(Fahrzeug* f, double pz)
{
	this->vTanken(f);
	list<Weg*>::iterator it;
	it = this->abgehendeWege.begin();
	(*it)->vAnnahme(f,pz);

}
void Kreuzung::vAnnahme(Fahrzeug* f)
{
	this->vTanken(f);
	this->abgehendeWege.front()->vAnnahme(f);
}


Weg* Kreuzung::ptZufaeligerWeg(Weg* w)
{
	list<Weg*>::iterator it = this->abgehendeWege.begin();
	
	if(this->abgehendeWege.size()==1&&this->abgehendeWege.front() == w)
	{
		return w;
	}

	while(true)
	{
		if((int)this->abgehendeWege.size()==0)
		{
			throw "Sackgasse!";
		}
		
		int irand = rand()%(int)this->abgehendeWege.size();
		
		for(int i=0;i<irand;i++)
		{
			it++;
		}
		if((*it)!=w)
		{
			return (*it);
		}
	}
	
	return 0;
}

void Kreuzung::vAbfertigung()
{
	list<Weg*>::iterator it = this->abgehendeWege.begin();
	while(it!=this->abgehendeWege.end())
	{
		(*it)->vAbfertigung();
		it++;
	}
}

ostream& Kreuzung::ostreamAusgabe(ostream& s)
{
	AktivesVO::ostreamAusgabe(s);
	list<Weg*>::iterator it = this->abgehendeWege.begin();
	
	while(it!=this->abgehendeWege.end())
	{
		s<<(*(*it))<<"\n";	
		it++;
	}
	return s;
}

istream& Kreuzung::istreamEingabe(istream& s)
{
	string command="";
	char c;
	int val=0;
	while((c = s.get()) && s.good())
	{

		if(c==' '||c=='\n')
		{

			switch(val)
			{
			case 0:
				this->p_sName = command;	
				cout<<"Name gelesen: "<<this->p_sName<<"\n";
				break;
			case 1:
				this->p_dTankstelle=strtod(command.c_str(),0);
				cout<<"Tankstelle: "<<this->p_dTankstelle<<"\n";
				break;	
			}

			val++;
			if(val==2)
			{
				break;
			}
			command="";
		}else
		{
			command+=c;
		}
		
	}

	

	objekte->insert(pair<string,AktivesVO*>(this->p_sName,this));
	//s.seekg(s.cur-line.length-)
	return s;
}



Kreuzung::~Kreuzung(void)
{
}
