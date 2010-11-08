#ifndef __GRASS__
#define __GRASS__
#include "Node.h"
/** 
 Sous classe de node, c'est un mur.
 **/


class Grass : public Node
{
	
public:
	//constructeur
	Grass();
	
	//constructeur avec coordonnées, longueur et hauteur
	Grass(int x, int y, int longueur, int hauteur );
	
	//destructeur
	~Grass();
	
};


#endif