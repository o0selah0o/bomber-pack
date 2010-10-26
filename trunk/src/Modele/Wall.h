#ifndef __WALL__
#define __WALL__
#include "Node.h"
/** 
Sous classe de node, c'est un mur.
**/


class Wall : public Node
{
	
public:
	Wall();
	Wall(int x, int y, int longueur, int hauteur );
	~Wall();
	
};


#endif