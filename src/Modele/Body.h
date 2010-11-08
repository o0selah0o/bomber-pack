#ifndef __BODY__
#define __BODY__
#include "Node.h"
/** 
 Sous classe de node, c'est une représentation du "contour de craie" d'une corps
 **/


class Body : public Node
{
	
public:
	//constructeur
	Body();
	
	//constructeur avec coordonnées d'apparition
	Body(int _x, int _y);
	
	//destructeur
	~Body();
	
};


#endif