#include "Projectile.h"
#include "Bullet.h"

Bullet::Bullet():Projectile()
{
	
}

Bullet::~Bullet(){
	
}

Bullet::Bullet(int _x ,int _y, int _dx, int _dy): Projectile(_x,_y,_dx,_dy)
{	
	longueur=2;
	hauteur=2;
	speed=5;
	range=400;
	power=20;
	symbole='o';
}


