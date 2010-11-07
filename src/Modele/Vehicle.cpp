#include "Vehicle.h"
#include "Node.h"
#include "Bullet.h"
#include "Obus.h"


Vehicle::Vehicle(int _x, int _y, int longueur, int hauteur):Node(_x,_y,longueur,hauteur)
{
	angle = 0;
	anglePrec=0;
	used=false;
	destroyed=false;
	hp=100;
	
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
	if((int)(getCenterY() - deca - longueur/2)>0){
		y= y - deca;
		
	}
	
}

void Vehicle::moveBack(float coeff,int h,int l){
	int deca=(int)(speed * coeff);
	angle=90;
	int temp = getCenterY()+deca+longueur/2;
	if(temp+5 < l){
		y=y + deca;
	}
	
	
}

void Vehicle::moveLeft(float coeff,int h,int l){
	float deca=(int)	(speed * coeff )	;
	angle=0;
	if( (int)(getCenterX() - deca - longueur/2)>0){
		x=x - deca ;
		
	}
	
}

void Vehicle::moveRight(float coeff,int h,int l){
	int deca=	(int)(speed* coeff );
	angle=180;
	int temp = getCenterX()+deca+longueur/2;
	if(temp-5 < h){
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
	int _x=getCenterX();
	int _y=getCenterY();
	if(used){
		Obus* bul=new Obus(_x,_y,_dx,_dy);
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