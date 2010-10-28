#include "Jeep.h"

Jeep::Jeep(int _x, int _y): Vehicle(_x,_y,longueur,hauteur)
{
	symbole = 'j';
	speed= 60;
	hauteur=70;
	longueur=110;
}

Jeep::~Jeep(){
	
}