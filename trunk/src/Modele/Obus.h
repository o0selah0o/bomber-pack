#ifndef __OBUS__
#define __OBUS__
#include "Projectile.h"

//classe représentant un obus tiré par un char
class Obus:public Projectile
{
public:
	//constructeur
	Obus();
	
	//constructeur avec coordonnées de départ, coordonnées de la destination
	Obus(int _x,int _y,int _dx,int _dy);
	
	//destructeur
	~Obus();	
	
};

#endif