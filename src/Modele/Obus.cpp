#include "Obus.h"


Obus::Obus(){
	
}
Obus::Obus(int _x,int _y,int _dx,int _dy):Projectile(_x,_y,_dx,_dy)
{
	power=50;
	speed=1;
}
Obus::~Obus(){
	
}