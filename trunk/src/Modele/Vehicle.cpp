#include "Vehicle.h"
#include "Node.h"


Vehicle::Vehicle(int _x, int _y, int longueur, int hauteur):Node(_x,_y,longueur,hauteur)
{
	hp=100;
}

Vehicle::~Vehicle()
{
	
}

void Vehicle::moveUp(){
	y=y-speed;
}

void Vehicle::moveBack(){
	y=y+speed;
}

void Vehicle::moveLeft(){
	x=x-speed;
}

void Vehicle::moveRight(){
	x=x+speed;
}

int Vehicle::getSpeed(){
	return speed;
}