#ifndef __WATER
#define __WATER
#include "Node.h"
/** 
 Sous classe de node, représentant de l'eau
 **/


class Water: public Node
{
public:
	
	//constructeur
	Water();
	
	//constructeur avec position, longueur et hauteur
	Water(int _x, int _y, int longueur, int hauteur);
	
	//Destructeur
	~Water();
	
}
;

#endif