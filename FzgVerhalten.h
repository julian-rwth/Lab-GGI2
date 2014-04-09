#pragma once
class Weg;
class Fahrzeug;

class FzgVerhalten
{
public:

	FzgVerhalten(Weg*);
	virtual ~FzgVerhalten(void);
	virtual double dStrecke(Fahrzeug*,double)=0;

protected:
	Weg* p_ptAktuellerWeg;
};
