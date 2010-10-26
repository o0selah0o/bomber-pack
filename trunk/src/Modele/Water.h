#ifndef __WATER
#define __WATER
#include "Node.h"
/** 
 Sous classe de node, représentant de l'eau
 **/


class Water: public Node
{
public:
	Water();
	Water(int _x, int _y, int longueur, int hauteur);
	~Water();
	
}
;

#endif