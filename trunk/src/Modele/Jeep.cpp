#include "Jeep.h"

Jeep::Jeep(int _x, int _y): Vehicle(_x,_y)
{
	symbole = 'j';
	speed= 300;
	hauteur=60;
	longueur=120;
	destroyed=false;
}

Jeep::~Jeep(){
	
}