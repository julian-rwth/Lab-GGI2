#pragma once
class Weg;
#include "FzgVerhalten.h"

class FzgParken :
	public FzgVerhalten
{

private:
	double p_dStartZeit;

public:
	FzgParken(Weg*,double StartZeit);
	double dStrecke(Fahrzeug* fzg,double time);
	virtual ~FzgParken(void);
};
