#include "Tank.h"
#include "Obus.h"

Tank::Tank(int _x, int _y): Vehicle(_x,_y)
{
	symbole = 't';
	speed=400;
	hauteur=60;
	longueur=120;
	destroyed=false;
	x=x-longueur;
	y=y-hauteur;
}


Tank::~Tank(){
	
}




Projectile* Tank::fire(int _dx,int _dy){
	int _x=getCenterX();
	int _y=getCenterY();
	if(used){
		Obus* ob=new Obus(_x,_y,_dx,_dy);
		return ob;
	}else {
		return NULL;
	}
	
}