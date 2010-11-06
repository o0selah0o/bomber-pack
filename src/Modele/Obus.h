#ifndef __OBUS__
#define __OBUS__
#include "Projectile.h"

//classe représentant un obus tiré par un char
class Obus:public Projectile
{
public:
	
	Obus();
	Obus(int _x,int _y,int _dx,int _dy,int _h,int _l);
	~Obus();	
	
};

#endif