#ifndef __WALL__
#define __WALL__
#include "Node.h"
/** 
Sous classe de node, c'est un mur.
**/


class Wall : public Node
{
	
public:
	//Constructeur
	Wall();
	
	//Constructeur avec coordonnées, hauteur et longueur
	Wall(int x, int y, int longueur, int hauteur );
	
	//destructeur
	~Wall();
	
};


#endif