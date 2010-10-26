#ifndef __BULLET
#define __BULLET
#include "Projectile.h"

//classe représentant une balle
class Bullet:public Projectile
{
	
public:
	
	Bullet();
	~Bullet();
	Bullet(int _dx, int _dy);
	
};

#endif