#pragma once
class Fahrzeug;
class Weg;

class FahrAusnahme
{
protected:
	Fahrzeug* p_ptFahrzeug;
	Weg* p_ptWeg;

public:
	FahrAusnahme(Fahrzeug*,Weg*);
	virtual ~FahrAusnahme(void);
	virtual void vBearbeiten()=0;
};
