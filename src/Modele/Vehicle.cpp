#include "Vehicle.h"
#include "Node.h"


Vehicle::Vehicle(int _x, int _y, int longueur, int hauteur):Node(_x,_y,longueur,hauteur)
{
	hp=100;
}

Vehicle::~Vehicle()
{
	
}

void Vehicle::moveUp(float coeff){
	y=y-speed;
}

void Vehicle::moveBack(float coeff){
	y=y+speed;
}

void Vehicle::moveLeft(float coeff){
	x=x-speed;
}

void Vehicle::moveRight(float coeff){
	x=x+speed;
}

int Vehicle::getSpeed(){
	return speed;
}