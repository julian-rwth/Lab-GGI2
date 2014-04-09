#include "FzgParken.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Losfahren.h"

extern double dGlobaleZeit;

FzgParken::FzgParken(Weg* w,double StartZeit):FzgVerhalten(w)
{
	this->p_dStartZeit = StartZeit;
}
double FzgParken::dStrecke(Fahrzeug* fzg,double time)
{
	if(dGlobaleZeit>=p_dStartZeit)
	{
		//exit(2);
		throw new Losfahren(fzg,this->p_ptAktuellerWeg);
	}
	else
	{
		return 0.0;
	}
}

FzgParken::~FzgParken(void)
{
}
