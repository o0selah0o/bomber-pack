#ifndef __JEEP
#define __JEEP
#include "Vehicle.h"
/** 
 Sous classe de vehicle, représentant une jeep**/


class Jeep: public Vehicle
{
public:
	
	//Constructeur avec coordonnées d'apparition
	Jeep(int _x, int _y);
	
	//Constructeur 
	Jeep();
	
	//Destructeur
	~Jeep();	
	
};


#endif