#ifndef __BODY__
#define __BODY__
#include "Node.h"
/** 
 Sous classe de node, c'est un mur.
 **/


class Body : public Node
{
	
public:
	Body();
	Body(int _x, int _y, int longueur, int hauteur,char _symbole);
	~Body();
	
};


#endif