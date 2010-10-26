#include "Tank.h"

Tank::Tank(int _x, int _y): Vehicle(_x,_y,longueur,hauteur)
{
	symbole = 't';
	speed=30;
	hauteur=85;
	longueur=170;
}


