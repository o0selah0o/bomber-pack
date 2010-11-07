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
		facteur= (int) 45/distanceDA;
		xb= ((_dx-_x)* facteur)+_x;
		yb= ((_dy-_y)* facteur)+_y;
		x=xb;
		y=yb;
	}
	if( ( _x > dx) and (_y < _dy)){
		distanceDA= pow(_dx - _x,2) + pow(_dy - _y,2);
		distanceDA=sqrt(distanceDA);
		facteur= (int) 45/distanceDA;
		xb= ((_dx-_x)* facteur)+_x;
		yb= ((_dy-_y)* facteur)+_y;
		x=xb;
		y=yb;
	}
	if( ( _x > _dx) and (_y > _dy)){
		distanceDA= pow(dx - x,2) + pow(_dy - _y,2);
		distanceDA=sqrt(distanceDA);
		facteur=(int) 45/distanceDA;
		xb= ((_dx-_x)* facteur)+_x;
		yb= ((_dy-_y)* facteur)+_y;
		x=xb;
		y=yb;
	}
	if( ( _x < _dx) and (_y > _dy)){
		distanceDA= pow(_dx - _x,2) + pow(_dy - _y,2);
		distanceDA=sqrt(distanceDA);
		facteur=(int) 45/distanceDA;
		xb= ((_dx-_x)* facteur)+_x;
		yb= ((_dy-_y)* facteur)+_y;
		x=xb;
		y=yb;
	}
	if (_x==_dx and  _y < _dy){
		x=_dx;
		y=_y+30;
	}
	if (_y==_dy and _x <_dx){
		x=_x+30;
		y=_dy;
	}
	
	if (_y==_dy and _dx < _x){
		x=_x-30;
		y=_dy;
	}
	
	if (_x==_dx and _dy < _y){
		x=_dx;
		y=_y-30;
	}
}

void Projectile::parcourir(float coeff){
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
	
	if (x==dx and  y < dy){
		x=dx;
		y=y+speed;
	}
	if (y==dy and x <dx){
		x=x+speed;
		y=dy;
	}
	
	if (y==dy and dx < x){
		x=x-speed;
		y=dy;
	}
	
	if (x==dx and dy < y){
		x=dx;
		y=y-speed;
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