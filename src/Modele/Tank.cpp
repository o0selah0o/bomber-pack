#include "Tank.h"
#include "Obus.h"

Tank::Tank(int _x, int _y): Vehicle(_x,_y)
{
	symbole = 't';
	speed=30;
	hauteur=60;
	longueur=120;
}


Tank::~Tank(){
	
}




Projectile* Tank::fire(int _dx,int _dy){
	if(used){
		Obus* ob=new Obus(x,y,_dx,_dy);
		return ob;
	}else {
		return NULL;
	}
	
}