#include "Fahrrad.h"
#include "SimuClient.h"
#include "Weg.h"
Fahrrad::Fahrrad(string sName):Fahrzeug(sName)
{

}

Fahrrad::Fahrrad()
{

}

Fahrrad::Fahrrad( string sName,double dMaxGeschindigkeit ):Fahrzeug(sName,dMaxGeschindigkeit)
{

}

Fahrrad::~Fahrrad(void)
{
}

void Fahrrad::vZeichnen(Weg* w)
{
  bZeichneFahrrad(this->p_sName,w->p_sName,(  this->GetdAbschnittStrecke() / w->Getp_dLaenge()  ),this->dGeschwindigkeit());
}

double Fahrrad::dGeschwindigkeit()
{
	double geschwindigkeit = pow( 0.9,(this->p_dGesamtStrecke/20) ) * this->p_dMaxGeschwindigkeit;
	if( geschwindigkeit > 12)
	{
		return geschwindigkeit;
	}else
	{
		return 12;	
	}
}

void Fahrrad::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout<<"\t\t\t"<<this->dGeschwindigkeit();
}
ostream& Fahrrad::ostreamAusgabe(ostream& s)
{
	Fahrzeug::ostreamAusgabe(s);
	s<<"\t\t\t"<<this->dGeschwindigkeit();
	return s;
}
istream& Fahrrad::istreamEingabe(istream& s)
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
				cout<<"Max V "<<this->p_dMaxGeschwindigkeit<<"\n";
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


