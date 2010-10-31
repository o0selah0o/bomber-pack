#include "Vehicle.h"
#include "Node.h"


Vehicle::Vehicle(int _x, int _y, int longueur, int hauteur):Node(_x,_y,longueur,hauteur)
{
	
	hp=100;
}

Vehicle::Vehicle(int _x, int _y):Node(_x,_y)
{
	hp=100;
}

Vehicle::~Vehicle()
{
	
}

void Vehicle::moveUp(float coeff,int h,int l){
	float deca=(int)	(speed * coeff);
	if((int)(y - deca - hauteur)>0)
		y= y - deca;
}

void Vehicle::moveBack(float coeff,int h,int l){
	int deca=(int)(speed * coeff);
	int temp = y+deca;
	if(temp+5+hauteur < l)
		y=y + deca;
}

void Vehicle::moveLeft(float coeff,int h,int l){
	float deca=(int)	(speed * coeff )	;
	if( (int)(x - deca - longueur)>0)
		x=x - deca ;
}

void Vehicle::moveRight(float coeff,int h,int l){
	int deca=	(int)(speed* coeff );
	int temp = x+deca;
	if(temp-5-longueur < h)
		x=x + deca;
}

int Vehicle::getSpeed(){
	return speed;
}

void Vehicle::setUsed(bool used){
	used=used;
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

void Vehicle::setDestroyed(bool state){
	destroyed=state;
}

bool Vehicle::isUsed(){
	return used;
}