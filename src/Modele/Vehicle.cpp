#include "Vehicle.h"
#include "Node.h"
#include "Bullet.h"


Vehicle::Vehicle(int _x, int _y, int longueur, int hauteur):Node(_x,_y,longueur,hauteur)
{
	used=false;
	destroyed=false;
	hp=100000;
}

Vehicle::Vehicle(int _x, int _y):Node(_x,_y)
{	
	used=false;
	destroyed=false;
	hp=1000000;
}

Vehicle::~Vehicle()
{
	
}

void Vehicle::moveUp(float coeff,int h,int l){
	float deca=(int)	(speed * coeff);
	if((int)(y - deca - hauteur)>0){
		printf("moveUP\n");
		y= y - deca;
	}
		
}

void Vehicle::moveBack(float coeff,int h,int l){
	int deca=(int)(speed * coeff);
	int temp = y+deca;
	if(temp+5+hauteur < l){
		printf("moveBACK\n");
		y=y + deca;
	}
		
}

void Vehicle::moveLeft(float coeff,int h,int l){
	float deca=(int)	(speed * coeff )	;
	if( (int)(x - deca - longueur)>0){
		printf("moveLEFT\n");
		x=x - deca ;
	}
		
}

void Vehicle::moveRight(float coeff,int h,int l){
	int deca=	(int)(speed* coeff );
	int temp = x+deca;
	if(temp-5-longueur < h){
		printf("moveRIGHT\n");
		x=x + deca;
	}
		
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