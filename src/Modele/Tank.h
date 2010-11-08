#ifndef __TANK
#define __TANK
#include "Vehicle.h"
#include "Projectile.h"
/** 
 Sous classe de vehicle, représentant un char**/


class Tank: public Vehicle
{
public:
	//constructeur
	Tank();
	
	//constructeur avec coordonnées d'apparition
	Tank(int _x, int _y);
	
	//destructeur
	~Tank();
	
	//méthode permettant au char de tiré dans une direction dx, dy
	Projectile* fire(int _dx,int _dy);

	
};


#endif