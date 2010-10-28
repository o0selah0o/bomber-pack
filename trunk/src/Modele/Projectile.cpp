#include "Projectile.h"
#include "math.h"
Projectile::Projectile(){
	
}

Projectile::~Projectile(){
	
}
Projectile::Projectile(int _x,int _y,int _dx,int _dy){
	dx=_dx;
	dy=_dy;
	parcouru=0;
	double xb,yb,facteur,distanceDA;
	if( ( _x < _dx) and (_y < _dy)){
		distanceDA= pow(_dx - _x,2) + pow(_dy - _y,2);
		distanceDA=sqrt(distanceDA);
		facteur= 10/distanceDA;
		xb= ((_dx-_x)* facteur)+_x;
		yb= ((_dy-_y)* facteur)+_y;
		x=xb;
		y=yb;
	}
	if( ( _x > dx) and (_y < _dy)){
		distanceDA= pow(_dx - _x,2) + pow(_dy - _y,2);
		distanceDA=sqrt(distanceDA);
		facteur= 10/distanceDA;
		xb= ((_dx-_x)* facteur)+_x;
		yb= ((_dy-_y)* facteur)+_y;
		x=xb;
		y=yb;
	}
	if( ( _x > _dx) and (_y > _dy)){
		distanceDA= pow(dx - x,2) + pow(_dy - _y,2);
		distanceDA=sqrt(distanceDA);
		facteur= 10/distanceDA;
		xb= ((_dx-_x)* facteur)+_x;
		yb= ((_dy-_y)* facteur)+_y;
		x=xb;
		y=yb;
	}
	if( ( _x < _dx) and (_y > _dy)){
		distanceDA= pow(_dx - _x,2) + pow(_dy - _y,2);
		distanceDA=sqrt(distanceDA);
		facteur= 10/distanceDA;
		xb= ((_dx-_x)* facteur)+_x;
		yb= ((_dy-_y)* facteur)+_y;
		x=xb;
		y=yb;
	}
	if (_x==_dx){
		x=_dx;
		y=_y+10;
	}
	if (_y==_dy){
		x=_x+10;
		y=_dy;
	}
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
		xb= ((dx-x)* facteur)+x;
		yb= ((dy-y)* facteur)+y;
		x=xb;
		y=yb;
	}
	if( ( x > dx) and (y > dy)){
		distanceDA= pow(dx - x,2) + pow(dy - y,2);
		distanceDA=sqrt(distanceDA);
		facteur= speed/distanceDA;
		xb= ((dx-x)* facteur)+x;
		yb= ((dy-y)* facteur)+y;
		x=xb;
		y=yb;
	}
	if( ( x < dx) and (y > dy)){
		distanceDA= pow(dx - x,2) + pow(dy - y,2);
		distanceDA=sqrt(distanceDA);
		facteur= speed/distanceDA;
		xb= ((dx-x)* facteur)+x;
		yb= ((dy-y)* facteur)+y;
		x=xb;
		y=yb;
	}
	if (x==dx){
		y=y+speed;
	}
	if (y==dy){
		x=x+speed;
	}
	parcouru+=speed;
	
}


int Projectile::getParcouru(){
	return parcouru;
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