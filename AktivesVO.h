#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <map>
using namespace std;

class AktivesVO
{

protected:
	double p_dZeit;
	int p_iID;
private:
	static int p_iMaxID;
public:
	static map<string,AktivesVO*>* objekte;
	string p_sName;
	AktivesVO(void);
	AktivesVO(string name);
	virtual ~AktivesVO(void);

	static AktivesVO* pt_Objekt(string name);

	virtual void vAbfertigung()=0;
	virtual ostream& ostreamAusgabe(ostream& s); 
	virtual istream& istreamEingabe(istream& s);

};

ostream& operator<<(ostream& s, AktivesVO& f);
istream & operator>> (istream &s, AktivesVO& v);