#include "FzgFahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Streckenende.h"


FzgFahren::FzgFahren(Weg* w):FzgVerhalten(w)
{

}

#include"AktivesVO.h"
#include"LazyListe.h"

FzgFahren::~FzgFahren(void)
{
}

double FzgFahren::dStrecke(Fahrzeug* fzg,double time)
{
	if( (fzg->GetdAbschnittStrecke()+fzg->dGeschwindigkeit()*time)>this->p_ptAktuellerWeg->Getp_dLaenge() )
	{
		if(this->p_ptAktuellerWeg->Getp_dLaenge()-fzg->GetdAbschnittStrecke()==0)
		{	
			//exit(0);
			throw new Streckenende(fzg,this->p_ptAktuellerWeg);
		}else
		{
			LazyListe<Fahrzeug*>::iterator it = this->p_ptAktuellerWeg->p_ptFahrzeuge.begin();
			
			double move=0;
			while(it!=this->p_ptAktuellerWeg->p_ptFahrzeuge.end())
			{
				if((*it)->GetdAbschnittStrecke()>fzg->GetdAbschnittStrecke()&&(*it)->getTankinhalt()>0.0)
				{
					if(move==0)
					move = (*it)->GetdAbschnittStrecke()-fzg->GetdAbschnittStrecke();
					else if(move>(*it)->GetdAbschnittStrecke()-fzg->GetdAbschnittStrecke())
					move = (*it)->GetdAbschnittStrecke()-fzg->GetdAbschnittStrecke();
				}
				it++;
			}
			if(move>0)
			{
				return move;
			}
			return this->p_ptAktuellerWeg->Getp_dLaenge()-fzg->GetdAbschnittStrecke();
		}

	}else
	{
		LazyListe<Fahrzeug*>::iterator it = this->p_ptAktuellerWeg->p_ptFahrzeuge.begin();
		double move=0;	
		while(it!=this->p_ptAktuellerWeg->p_ptFahrzeuge.end())
			{
				if((*it)->GetdAbschnittStrecke()<fzg->GetdAbschnittStrecke()+fzg->dGeschwindigkeit()*time&&(*it)->GetdAbschnittStrecke()>fzg->GetdAbschnittStrecke()&&(*it)->getTankinhalt()>0.0)
				{
					if(move==0)
					move = (*it)->GetdAbschnittStrecke()-fzg->GetdAbschnittStrecke();
					else if(move>(*it)->GetdAbschnittStrecke()-fzg->GetdAbschnittStrecke())
					move = (*it)->GetdAbschnittStrecke()-fzg->GetdAbschnittStrecke();
				}
			it++;	
		}
			if(move>0)
			{
				return move;
			}
		return fzg->dGeschwindigkeit()*time;
	}
	return 0;
}