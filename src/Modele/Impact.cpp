#include "Impact.h"
#include "Node.h"


Impact::Impact():Node(){
	symbole='i';
}
Impact::Impact(int _x, int _y, int longueur, int hauteur): Node(_x,_y,longueur,hauteur)
{
	symbole = 'i';
}



Impact::~Impact(){
	
}