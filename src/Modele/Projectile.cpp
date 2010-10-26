#include "Projectile.h"

Projectile::Projectile(){
	
}

Projectile::Projectile(int _dx,int _dy){
	dx=_dx;
	dy=_dy;
}

void Projectile::parcourir(){
	
	
}

int Projectile::getSpeed(){
	return speed;
}

int Projectile::getRange(){
	return range;
}

int Projectile::getPower(){
	return power;
}

int Projectile::getDy(){
	return dy;
}

int Projectile::getDx(){
	return dx;
}