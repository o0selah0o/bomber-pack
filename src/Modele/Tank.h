#ifndef __TANK
#define __TANK
#include "Vehicle.h"
#include "Projectile.h"
/** 
 Sous classe de vehicle, représentant un char**/


class Tank: public Vehicle
{
public:
	Tank();
	Tank(int _x, int _y);
	~Tank();
	Projectile* fire(int _dx,int _dy);

	
};


#endif