#include "Vehicle.h"
#include "Node.h"
#include "Bullet.h"


Vehicle::Vehicle(int _x, int _y, int longueur, int hauteur):Node(_x,_y,longueur,hauteur)
{
	angle = 0;
	anglePrec=0;
	used=false;
	destroyed=false;
	hp=100000;
	
}

Vehicle::Vehicle(int _x, int _y):Node(_x,_y)
{	
	angle = 0;
	anglePrec=0;
	used=false;
	destroyed=false;
	hp=1000000;
}

Vehicle::~Vehicle()
{
	
}

void Vehicle::moveUp(float coeff,int h,int l){
	float deca=(int)	(speed * coeff);
	angle=270;
	if((int)(y - deca - hauteur)>0){
		y= y - deca;
		
	}
	
}

void Vehicle::moveBack(float coeff,int h,int l){
	int deca=(int)(speed * coeff);
	angle=90;
	int temp = y+deca;
	if(temp+5+hauteur < l){
		y=y + deca;
	}
	
	
}

void Vehicle::moveLeft(float coeff,int h,int l){
	float deca=(int)	(speed * coeff )	;
	angle=0;
	if( (int)(x - deca - longueur)>0){
		x=x - deca ;
		
	}
	
}

void Vehicle::moveRight(float coeff,int h,int l){
	int deca=	(int)(speed* coeff );
	angle=180;
	
	
	int temp = x+deca;
	if(temp-5-longueur < h){
		x=x + deca;
		
		
	}
	
}

int Vehicle::getSpeed(){
	return speed;
}

void Vehicle::setUsed(bool _used){
	used=_used;
}

void Vehicle::hit(int damages){
	hp=hp-damages;
	if(hp <= 0){
		destroyed=true;
	}
}

bool Vehicle::isDestroyed(){
	return destroyed;
}

Projectile* Vehicle::fire(int _dx,int _dy){
	if(used){
		Bullet* bul=new Bullet(x,y,_dx,_dy);
		return bul;
	}else {
		return NULL;
	}
	
}

void Vehicle::setDestroyed(bool state){
	destroyed=state;
}

bool Vehicle::isUsed(){
	return used;
}

double Vehicle::getAngle(){
	return angle;
}