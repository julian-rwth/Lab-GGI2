#include "Welt.h"
#include "SimuClient.h"
Welt::Welt(void)
{
}

void Welt::vSimulation()
{
	list<Kreuzung*>::iterator it = this->wege.begin();
	while(it!=this->wege.end())
	{
		(*it)->vAbfertigung();
		it++;
	}
}


void Welt::vEinlesenMitGrafik(ifstream *s)
{
	std::string line;
		string command;
		
		
		char c;
		while((c = s->get()) && s->good())
		{
			if(c!='\n')
			{
				command+=c;
			}
			if(command=="STRASSE ")
			{
			
				string k1;
				string k2;
				string w1;
				string w2;
				int laenge;

				Kreuzung* kk1,*kk2;

				string line;
				getline(*s,line);
				
				int index=0;
				int val=0;
				int off=0;
					
				while((index=line.find(" ",index+1))!=string::npos)
				{
					switch(val)
					{
						case 0:
							k1=line.substr(off,index-off);
							kk1 = (Kreuzung*)AktivesVO::pt_Objekt(k1);
							break;
						case 1:
							k2=line.substr(off,index-off);
							kk2 = (Kreuzung*)AktivesVO::pt_Objekt(k2);
							break;
						case 2:
							w1=line.substr(off,index-off);
							break;
						case 3:
							w2=line.substr(off,index-off);
							break;			
					}
					if(val<=3)
					{
					val++;
					off=index+1;
					}else
					{
						break;
					}

				}

				laenge = (int)strtod(line.substr(off).c_str(),0);
				kk1->vVerbinde(w2,w1,laenge,kk2);

				int koordinaten=0;
				int startindex=index;
				while((index=line.find(" ",index+1))!=string::npos)
				{
					koordinaten++;
				}
				int* xy = new int[koordinaten];
				index=startindex;
				off=index;
				for(int i=-1;i<koordinaten;i++)
				{
					index=line.find(" ",index+1);
					if(i>=0)
					{
					
					xy[i]=(int)atoi(line.substr(off,index-off).c_str());
					
					}
					off=index;
				}
				bZeichneStrasse(w1,w2,laenge,(koordinaten/2),xy);

				command="";
			}


			if(command=="KREUZUNG ")
			{
				Kreuzung* kneu=new Kreuzung("",0);
				*s>>*kneu;
				int x1,y1;
				*s>>x1;
				*s>>y1;
				
				this->wege.push_back(kneu);
				::bZeichneKreuzung(x1,y1);
				command="";
			}
			if(command=="PKW ")
			{
				PKW* f = new PKW();
				*s>>*f;
				string ks;
				*s>>ks;
				double los;
				*s>>los;
				command="";
				((Kreuzung*)AktivesVO::pt_Objekt(ks))->vAnnahme(f,los);
			}
			if(command=="FAHRRAD ")
			{
				Fahrrad* f = new Fahrrad();
				*s>>*f;
				string ks;
				*s>>ks;
				double los;
				*s>>los;
				command="";
				((Kreuzung*)AktivesVO::pt_Objekt(ks))->vAnnahme(f,los);
			}
			
		}

}


void Welt::vEinlesen(ifstream* s)
{

		std::string line;
		string command;
		
		
		char c;
		while((c = s->get()) && s->good())
		{
			if(c!='\n')
			{
				command+=c;
			}
			if(command=="STRASSE ")
			{
			
				string k1;
				string k2;
				string w1;
				string w2;
				int laenge;

				Kreuzung* kk1,*kk2;

				string line;
				getline(*s,line);
				
				int index=0;
				int val=0;
				int off=0;
					
				while((index=line.find(" ",index+1))!=string::npos)
				{
					switch(val)
					{
						case 0:
							k1=line.substr(off,index-off);
							kk1 = (Kreuzung*)AktivesVO::pt_Objekt(k1);
							break;
						case 1:
							k2=line.substr(off,index-off);
							kk2 = (Kreuzung*)AktivesVO::pt_Objekt(k2);
							break;
						case 2:
							w1=line.substr(off,index-off);
							break;
						case 3:
							w2=line.substr(off,index-off);
							break;			
					}
					if(val<=3)
					{
					val++;
					off=index+1;
					}

				}

				laenge = (int)strtod(line.substr(off).c_str(),0);
				kk1->vVerbinde(w1,w2,laenge,kk2);
			
				command="";
			}


			if(command=="KREUZUNG ")
			{
				Kreuzung* kneu=new Kreuzung("",0);
				*s>>*kneu;
				this->wege.push_back(kneu);
				command="";
			}
			if(command=="PKW ")
			{
				PKW* f = new PKW();
				*s>>*f;
				string ks;
				*s>>ks;
				double los;
				*s>>los;
				command="";
				((Kreuzung*)AktivesVO::pt_Objekt(ks))->vAnnahme(f,los);
			}
			if(command=="FAHRRAD ")
			{
				Fahrrad* f = new Fahrrad();
				*s>>*f;
				string ks;
				*s>>ks;
				double los;
				*s>>los;
				command="";
				((Kreuzung*)AktivesVO::pt_Objekt(ks))->vAnnahme(f,los);
			}
			
		}

	
}

Welt::~Welt(void)
{
}
