#include "AktivesVO.h"

int AktivesVO::p_iMaxID = 0;
map<string,AktivesVO*>* AktivesVO::objekte = new map<string,AktivesVO*>();

AktivesVO::AktivesVO(void)
{
	this->p_iID = AktivesVO::p_iMaxID;
	AktivesVO::p_iMaxID++;
	
}
AktivesVO::AktivesVO(string name)
{
	this->p_sName = name;
	this->p_iID = AktivesVO::p_iMaxID;
	AktivesVO::p_iMaxID++;

}
AktivesVO::~AktivesVO(void)
{
	AktivesVO::p_iMaxID--;
}

AktivesVO* AktivesVO::pt_Objekt(string name)
{
	AktivesVO::objekte->find(name);
	if(((*AktivesVO::objekte).find(name))==((*AktivesVO::objekte).end()))
	{
		throw "Objekt nicht vorhanden";
	}
	return (AktivesVO::objekte->find(name))->second;
}

ostream& AktivesVO::ostreamAusgabe(ostream& s)
{
	s<<this->p_iID<<"\t"<<this->p_sName<<"\t:\t";
	return s;
}

istream& AktivesVO::istreamEingabe(istream& s)
{
	return s;
}

istream & operator >> (istream &s, AktivesVO& v)
{
    return v.istreamEingabe(s);
}

ostream& operator<<(ostream& s, AktivesVO& f)
{
	return f.ostreamAusgabe(s);
}
