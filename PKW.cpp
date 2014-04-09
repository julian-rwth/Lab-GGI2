#include "PKW.h"
#include "SimuClient.h"
#include "Weg.h"
#include "FzgVerhalten.h"

extern double dGlobaleZeit;

PKW::PKW( string sName,double dMaxGeschindigkeit,double dVerbrauch, double dTankvolumen ) : Fahrzeug(sName,dMaxGeschindigkeit)
{
	this->p_dTankinhalt = dTankvolumen/2;
	this->p_dVerbrauch = dVerbrauch;
	this->p_dTankvolumen = dTankvolumen;
}
PKW::PKW()
{

}
PKW::~PKW(void)
{
}

double PKW::getTankinhalt()
{
	return this->dVerbrauch();
}

double PKW::dVerbrauch()
{
	return this->p_dGesamtStrecke*this->p_dVerbrauch;
}

void PKW::vZeichnen(Weg* w)
{
	::bZeichnePKW(this->p_sName,w->p_sName,(this->GetdAbschnittStrecke()/w->Getp_dLaenge()),this->dGeschwindigkeit(),this->p_dTankinhalt);
}

double PKW::dTanken( double dMenge/* =0.0 */ )
{
	if(dMenge == 0)
	{
		p_dTankinhalt = p_dTankvolumen;
		return p_dTankvolumen;
	}else
	{
		if(dMenge>p_dTankvolumen)
		{
			p_dTankinhalt=p_dTankvolumen;
			return p_dTankvolumen;
		}
		if(dMenge<0)
		{
			return 0;
		}
		p_dTankinhalt = dMenge;
		return dMenge;
	}
}

void PKW::vAbfertigung()
{
	if(this->p_dTankinhalt>0.0)
	{ 
		//this->p_dTankinhalt -= this->p_dVerbrauch*(((dGlobaleZeit - p_dZeit)*this->p_dMaxGeschwindigkeit)/100);
		double gefahren = this->p_ptVerhalten->dStrecke(this,(dGlobaleZeit - p_dZeit));
		 
		this->p_dTankinhalt -= (gefahren/100)*this->p_dVerbrauch;
		
		if(this->p_dTankinhalt<0)
		{
			this->p_dTankinhalt=0;
		}
		Fahrzeug::vAbfertigung();
	}else
	{
		p_dZeit=dGlobaleZeit;
	}

}

void PKW::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout<<"\t"<<this->p_dTankinhalt<<"\t"<<(this->p_dGesamtStrecke*this->p_dVerbrauch/100)<<"\n";
}


ostream& PKW::ostreamAusgabe(ostream& s)
{
	
	return (Fahrzeug::ostreamAusgabe(s)<<"\t"<<this->p_dTankinhalt<<"\t"<<(this->p_dGesamtStrecke*this->p_dVerbrauch/100));
	
}
//istream& PKW::istreamEingabe(istream& s)
//{
//	std::string line;
//	getline(s,line);
//	cout<<"Parse PKW: "<<line<<"\n";
//	
//    int index=0;
//	int val=0;
//	int off=0;
//	
//	while((index=line.find(" ",index+1))!=string::npos)
//	{
//		switch(val)
//		{
//			case 0:
//				this->p_sName = line.substr(0,index);	
//				cout<<"Name gelesen: "<<this->p_sName<<"\n";
//				val++;
//				off=index;
//				break;
//			case 1:
//				this->p_dMaxGeschwindigkeit=strtod(line.substr(off,index).c_str(),0);
//				cout<<"Max v gelesen: "<<this->p_dMaxGeschwindigkeit<<"\n";
//				val++;
//				off=index;
//				break;
//			case 2:
//				this->p_dVerbrauch = strtod(line.substr(off,index).c_str(),0);
//				cout<<"Verbrauch gelesen: "<<this->p_dVerbrauch<<"\n";
//				val++;
//				off=index+1;
//				break;
//
//		}
//		
//	
//	}
//
//	this->p_dTankvolumen = strtod(line.substr(off).c_str(),0);
//	cout<<"Volumen gelesen: "<<this->p_dTankvolumen<<"\n";
//	this->p_dTankinhalt = this->p_dTankvolumen/2;
//
//	objekte->insert(pair<string,AktivesVO*>(this->p_sName,this));
//	//s.seekg(s.cur-line.length-)
//	return s;
//}


istream& PKW::istreamEingabe(istream& s)
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
				this->p_dMaxGeschwindigkeit=strtod(command.c_str(),0);
				cout<<"Max v gelesen: "<<this->p_dMaxGeschwindigkeit<<"\n";
				break;
			case 2:
				this->p_dVerbrauch = strtod(command.c_str(),0);
				cout<<"Verbrauch gelesen: "<<this->p_dVerbrauch<<"\n";
				break;
			case 3:
				this->p_dTankvolumen = strtod(command.c_str(),0);
				cout<<"Volumen gelesen: "<<this->p_dTankvolumen<<"\n";
				this->p_dTankinhalt = this->p_dTankvolumen/2;			
				break;

				
			}

			val++;
			if(val==4)
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




PKW& PKW::operator = (PKW &p)
{
	
	this->p_dTankinhalt = (p).p_dTankinhalt;
	this->p_dTankvolumen = (p).p_dTankvolumen;
	this->p_dVerbrauch = (p).p_dVerbrauch;
	
	this->p_dGesamtStrecke = p.p_dGesamtStrecke;
	this->p_dGesamtZeit = p.p_dGesamtZeit;
	this->p_dMaxGeschwindigkeit = p.p_dMaxGeschwindigkeit;
	this->p_dZeit = p.p_dZeit;
	this->p_sName = p.p_sName;
	return *this;
}
PKW& PKW::operator = (Fahrzeug &p)
{
	PKW* p2 = (PKW*)&p;
	this->p_dTankinhalt = p2->p_dTankinhalt;
	this->p_dTankvolumen = p2->p_dTankvolumen;
	this->p_dVerbrauch = p2->p_dVerbrauch;
	this->p_dGesamtStrecke = p2->p_dGesamtStrecke;
	this->p_dGesamtZeit = p2->p_dGesamtZeit;
	this->p_dMaxGeschwindigkeit = p2->p_dMaxGeschwindigkeit;
	this->p_dZeit = p2->p_dZeit;
	this->p_sName = p2->p_sName;
	return *this;
}