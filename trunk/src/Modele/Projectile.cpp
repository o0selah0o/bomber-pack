#include "Projectile.h"
#include "math.h"
Projectile::Projectile(){
	
}

Projectile::~Projectile(){
	
}
Projectile::Projectile(int _dx,int _dy){
	dx=_dx;
	dy=_dy;
}

void Projectile::parcourir(){
	double xb,yb,facteur,distanceDA;
	if( ( x < dx) and (y < dy)){
	   distanceDA= pow(dx - x,2) + pow(dy - y,2);
	   distanceDA=sqrt(distanceDA);
	   facteur= speed/distanceDA;
	   xb= ((dx-x)* facteur)+x;
	   yb= ((dy-y)* facteur)+y;
	   x=xb;
	   y=yb;
	}
	if( ( x > dx) and (y < dy)){
		distanceDA= pow(dx - x,2) + pow(dy - y,2);
		distanceDA=sqrt(distanceDA);
		facteur= speed/distanceDA;
		xb= ((x-dx)* facteur)-x;
		yb= ((dy-y)* facteur)+y;
		x=xb;
		y=yb;
	}
	if( ( x > dx) and (y > dy)){
		distanceDA= pow(dx - x,2) + pow(dy - y,2);
		distanceDA=sqrt(distanceDA);
		facteur= speed/distanceDA;
		xb= ((x-dx)* facteur)-x;
		yb= ((y-dy)* facteur)-y;
		x=xb;
		y=yb;
	}
	if( ( x < dx) and (y > dy)){
		distanceDA= pow(dx - x,2) + pow(dy - y,2);
		distanceDA=sqrt(distanceDA);
		facteur= speed/distanceDA;
		xb= ((dx-x)* facteur)+x;
		yb= ((y-dy)* facteur)-y;
		x=xb;
		y=yb;
	}
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

std::pair<double,double> Projectile::getTrajectoryAB(){
	double a= (dy - y) / ( dx - x);
	double b= y - (a*x);
	std::pair<double,double> p (a,b);
	return p;
}

int Projectile::getDy(){
	return dy;
}

int Projectile::getDx(){
	return dx;
}