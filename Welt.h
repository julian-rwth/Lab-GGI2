#pragma once

#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>
#include <fstream>

#include "Weg.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "AktivesVO.h"




using namespace std;
class Welt
{
private:
	list<Kreuzung*> wege;
public:
	Welt(void);
	void vEinlesen(ifstream *s);
	void vEinlesenMitGrafik(ifstream *s);
	void vSimulation();
	~Welt(void);
};
