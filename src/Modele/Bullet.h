#ifndef __BULLET
#define __BULLET
#include "Projectile.h"

//classe représentant une balle
class Bullet:public Projectile
{
	
public:
	//constructeur
	Bullet();
	
	//destructeur
	~Bullet();
	
	//constructeur avec coordonnées de départ et d'arrivée
	Bullet(int _x,int _y,int _dx, int _dy);
	
};

#endif