#include "Fahrzeug.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <vector>
#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include "AktivesVO.h"
#include "SimuClient.h"
#include "LazyListe.h"
#include "Fahrrad.h"
#include <stdlib.h>
#include <fstream>
#include "Welt.h"
using namespace std;


double dGlobaleZeit=0.0;

void vAufgabe_1()
{
	Fahrzeug f0("f0",60);
	Fahrzeug f1("f1",260);

	string name2="";
	getline(std::cin,name2);
	Fahrzeug *f2 = new Fahrzeug(name2,80);

	string name3="";
	getline(std::cin,name3);
	Fahrzeug *f3 = new Fahrzeug(name3,320);

	
	

	while(true)
	{
		f0.vAbfertigung();
		f1.vAbfertigung();
		f2->vAbfertigung();
		f3->vAbfertigung();
		
		dGlobaleZeit+=0.25;
		
		f0.vAusgabe();
		f1.vAusgabe();
		f2->vAusgabe();
		f3->vAusgabe();
		
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++\n";

		Sleep(10000);
	}


	delete f3;
	delete f2;
}
void vAufgabe_1_deb()
{
	
	Fahrzeug* feld[4];

	string name0="";
	getline(std::cin,name0);
	Fahrzeug *f0 = new Fahrzeug(name0,80);

	string name1="";
	getline(std::cin,name1);
	Fahrzeug *f1 = new Fahrzeug(name1,320);


	string name2="";
	getline(std::cin,name2);
	Fahrzeug *f2 = new Fahrzeug(name2,80);

	string name3="";
	getline(std::cin,name3);
	Fahrzeug *f3 = new Fahrzeug(name3,320);

	feld[0] = f0;
	feld[1] = f1;
	feld[2] = f2;
	feld[3] = f3;



	cout<<"ID"<<"\t"<<"Name"<<"\t:\t"<<"MaxKmh"<<"\t"<<"GesamtStrecke"<<"\n";
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++\n";


    for(int i=0;i<4;i++)
	{
		feld[i]->vAusgabe();		
	}

	feld[2] = NULL;

	for(int i=0;i<4;i++)
	{
		feld[i]->vAusgabe();
	}

	delete f0;
	delete f1;
	delete f3;
	delete f2;
}

void vAufgabe_2()
{
	cout<<"Wieviele PKW soll ich fuer sie erzeugen?\n";
	int anzahl_pkw=0;
	cin>>anzahl_pkw;
	cout<<"Wieviele Fahrraeder soll ich fuer sie erzeugen?\n";
	int anzahl_fahr=0;
	cin>>anzahl_fahr;
	
	vector<Fahrzeug*> fahrzeuge;
	
	for(int i=0;i<anzahl_pkw;i++)
	{
		fahrzeuge.push_back(new PKW("PKW",220,12,80));
	}
	for(int i=0;i<anzahl_fahr;i++)
	{
		fahrzeuge.push_back(new Fahrrad("Fahr",25));
	}



	cout<<"\n\nID"<<"\t"<<"Name"<<"\t:\t"<<"MaxKmh"<<"\t"<<"Str.\tTank\tVerbr.\tGeschw."<<"\n";
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	while(true)
	{
	    
		for(int i=0;i<anzahl_pkw+anzahl_fahr;i++)
		{
			fahrzeuge[i]->vAbfertigung();
			//fahrzeuge[i]->vAusgabe();
			cout<<*(fahrzeuge[i]);
			if(dGlobaleZeit==2.5)
			{
				cout<<"------> Tankstopp!\n";
				fahrzeuge[i]->dTanken();
			}
		}
    
		

		dGlobaleZeit+=0.25;

		Sleep(1000);
	}



}
void vAufgabe_3()
{

	cout<<"\n\nID"<<"\t"<<"Name"<<"\t:\t"<<"MaxKmh"<<"\t"<<"Str."<<"\tWeg.\tTank\tVerbr.\tGeschw."<<"\n";
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	Fahrzeug* a = new PKW("Audi",280,15);
	Fahrzeug* b = new PKW("Porsche",320,21,80);
	cout<<*a<<"\n"<<*b<<"\n";
	
	dGlobaleZeit+=0.25;
	b->vAbfertigung();

	cout<<*a<<"\n"<<*b<<"\n";
	
	*a=*b;
	
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	cout<<*a<<"\n"<<*b<<"\n";

}


void vAufgabe_4()
{
	Weg w("Buykerweg",300);
	PKW a("Audi A8",320,6);
	PKW b("BMW X3",230,6);
	
	w.vAnnahme(&a);
	w.vAnnahme(&b,0.25);
	cout<<w<<"\n";

	cout<<"\n\nID"<<"\t"<<"Name"<<"\t:\t"<<"MaxKmh"<<"\t"<<"Str."<<"\tWeg.\tTank\tVerbr.\tGeschw."<<"\n";
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	while(true)
	{
	 w.vAbfertigung();
	 cout<<w<<"\n";
	 cout<<a<<"\n";
	 cout<<b;
	 Sleep(1000);
	 ::dGlobaleZeit+=0.25;
	}
}

void vAufgabe_5()
{

	::bInitialisiereGrafik(800,600);
	
	int buy[] = {50,200,500,200};
	::bZeichneStrasse("Buykerweg","Dueppelstr",500,2,buy);
	
	
	Weg w1("Buykerweg",500);
	Weg w2("Dueppelstr",500);

	PKW a("AudiA8",120,2,80);
	PKW b("BMWX3",100,2,80);
	
	w1.vAnnahme(&a);
	w2.vAnnahme(&b);

	cout<<"\n\nID"<<"\t"<<"Name"<<"\t:\t"<<"MaxKmh"<<"\t"<<"Str."<<"\tWeg.\tTank\tVerbr.\tGeschw."<<"\n";
	cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

		
	while(true)
	{
	
	 ::vSetzeZeit(::dGlobaleZeit);
	
	 w1.vAbfertigung();
	 w2.vAbfertigung();

	 a.vZeichnen(&w1);
	 b.vZeichnen(&w2);

	 cout<<a<<"\n\n";
	 cout<<b<<"\n\n";

	 Sleep(500);
	 ::dGlobaleZeit+=0.3;

	}
}

void vAufgabe_6()
{

	
	Weg w1("Buykerweg",500);
	

	PKW a("AudiA8",120,2,80);
	PKW b("BMWX3",100,2,80);
	
	w1.vAnnahme(&a,0.6);
	w1.vAnnahme(&b);

	cout<<"\n\nID"<<"\t"<<"Name"<<"\t:\t"<<"MaxKmh"<<"\t"<<"Str."<<"\tWeg.\tTank\tVerbr.\tGeschw."<<"\n";
	cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

		
	while(true)
	{
	 
	w1.vAbfertigung();

	 cout<<a<<"\n\n";
	 cout<<b<<"\n\n";

	 Sleep(1000);
	 ::dGlobaleZeit+=0.3;

	}
}
void vAufgabe_6a()
{
	LazyListe<int> *liste = new LazyListe<int>();
	for(int i=0;i<10;i++)
	{
		liste->push_back(rand()%11);
	}
	liste->vAktualisieren();
	
	list<int>::iterator it;
	cout<<"\n\nausgabe\n";
	for(it=liste->begin();it!=liste->end();it++)
	{
		cout<<(*it)<<'\n';
	}
	
	for(it=liste->begin();it!=liste->end();it++)
	{
		if((*it)<5)
		{
			liste->erase(it);
		}
	}
cout<<"\n\nausgabe\n";
	for(it=liste->begin();it!=liste->end();it++)
	{
		cout<<(*it)<<'\n';
	}
	liste->vAktualisieren();
	cout<<"\n\nausgabe\n";
	for(it=liste->begin();it!=liste->end();it++)
	{
		cout<<(*it)<<'\n';
	}
	liste->push_back(1000);
	liste->push_front(-1);
	liste->vAktualisieren();
	cout<<"\n\nausgabe\n";
	for(it=liste->begin();it!=liste->end();it++)
	{
		cout<<(*it)<<'\n';
	}

	
}

void vAufgabe7()
{
	
	Weg w1("Buykerweg",500);
	
	PKW a("AudiA8",120,2,80);
	Fahrrad b("BMX",30);
	PKW c("Porsche",120,2,80);
	
	w1.vAnnahme(&a,0.9);
	w1.vAnnahme(&b,0.9);

	cout<<"\n\nID"<<"\t"<<"Name"<<"\t:\t"<<"MaxKmh"<<"\t"<<"Str."<<"\tWeg.\tTank\tVerbr.\tGeschw."<<"\n";
	cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

		
	while(true)
	{
	 
	 w1.vAbfertigung();

	 cout<<a<<"\n\n";
	 cout<<b<<"\n\n";
	 cout<<c<<"\n\n";

	 Sleep(1000);
	 
	 ::dGlobaleZeit+=0.3;
	 
	 if(::dGlobaleZeit == 1.2)
	 {
		w1.vAnnahme(&c,1.8);
	 }

	}

}

void vAufgabe_8()
{
	
	Kreuzung Kr1("Kr1",0);
	Kreuzung Kr2("Kr2",1000);
	Kreuzung Kr3("Kr3",0);
	Kreuzung Kr4("Kr4",0);
	
	Kr1.vVerbinde("W21","W12",40,&Kr2);
	Kr2.vVerbinde("W32a","W23a",115,&Kr3);
	Kr2.vVerbinde("W32b","W23b",40,&Kr3);
	Kr2.vVerbinde("W42","W24",55,&Kr4);
	Kr3.vVerbinde("W43","W34",85,&Kr4);
	Kr4.vVerbinde("W44b","W44b",130,&Kr4);

	cout<<"Weg system erstellt:\n\n";
	cout<<Kr1<<"\n";
	cout<<Kr2<<"\n";
	cout<<Kr3<<"\n";
	cout<<Kr4<<"\n";
	cout<<"ENDE Weg System\n";

	
	::bInitialisiereGrafik(1000,1000);
	
	int str1[] = {680,300,680,40};
	int str2[] = {680,300,850,300,970,390,970,500,850,570,680,570};
	int str3[] = {680,570,680,300};
	int str4[] = {320,300,680,300};
	int str5[] = {680,570,500,570,350,510,320,420,320,300};
	int str6[] = {320,300,320,150,200,60,80,90,70,250,170,300,320,300};


	::bZeichneStrasse("w21","w12",40,2,str1);
	::bZeichneStrasse("w32a","w23a",115,6,str2);
	::bZeichneStrasse("w32b","w23b",40,2,str3);
	::bZeichneStrasse("w42","w24",55,2,str4);
	::bZeichneStrasse("w43","w34",85,5,str5);
    ::bZeichneStrasse("w44b","w44b1",130,7,str6);
	
	PKW p1("Audi A8",120,5);

	Kr2.vAnnahme(&p1,0.6);
	
	while(true)
	{
	 cout<<"\nAbfertigen\n\n";
	 Kr1.vAbfertigung();
	 Kr2.vAbfertigung();
	 Kr3.vAbfertigung();
	 Kr4.vAbfertigung();
	 
	 Sleep(1000);
	 ::dGlobaleZeit+=0.3;
	}

}

void vAufgabe_9()
{
	std::ifstream is("VO.dat");
	PKW p1 = PKW();
	Fahrrad f1("  ");
	Kreuzung k1("",0);
	is>>p1;
	is>>f1;
	is>>k1;
}

void vAufgabe_9b()
{

	
	std::ifstream* is=new std::ifstream("SimuDisplay.dat");
	Welt w;
	
	::bInitialisiereGrafik(1000,1000);
	
	try
	{
		w.vEinlesenMitGrafik(is);
	while(1)
	{
		w.vSimulation();
		Sleep(10);
		::dGlobaleZeit+=0.05;
	}
	}catch(char* p)
	{ 
		cout<<"Error!"<<(p)<<"\n";
	}

}
void main()
{	
	
	//::vAufgabe_1();
	//::vAufgabe_1_deb();
	//::vAufgabe_2();
	//::vAufgabe_3();
	//::vAufgabe_4();
	//::vAufgabe_5();
	//::vAufgabe_6();
	//::vAufgabe_6a();
	//::vAufgabe7();
	//::vAufgabe_8();
	//::vAufgabe_9();
	::vAufgabe_9b();
	::system("Pause");
}