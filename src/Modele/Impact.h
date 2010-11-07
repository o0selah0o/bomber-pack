#ifndef __GRASS__
#define __GRASS__
#include "Node.h"
/** 
 Sous classe de node, c'est un mur.
 **/


class Impact : public Node
{
	
public:
	Impact();
	Impact(int x, int y, int longueur, int hauteur );
	~Impact();
	
};


#endif