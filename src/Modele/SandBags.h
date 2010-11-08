#ifndef __SANDBAGS
#define __SANDBAGS
#include "Node.h"
/** 
 Sous classe de node, représentant des sacs de sable
 **/


class SandBags: public Node
{
public:
	//constructeur
	SandBags();
	
	//constructeur avec coordonnées, hauteur et longueur
	SandBags(int _x, int _y, int longueur, int hauteur);
	
	//destructeur
	~SandBags();
	
};


#endif