#ifndef __JEEP
#define __JEEP
#include "Vehicle.h"
/** 
 Sous classe de vehicle, représentant une jeep**/


class Jeep: public Vehicle
{
public:
	Jeep(int _x, int _y);
	Jeep();
	~Jeep();	
	
};


#endif