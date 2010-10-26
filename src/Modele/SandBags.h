#ifndef __SANDBAGS
#define __SANDBAGS
#include "Node.h"
/** 
 Sous classe de node, représentant des sacs de sable
 **/


class SandBags: public Node
{
public:
	SandBags();
	SandBags(int _x, int _y, int longueur, int hauteur);
	~SandBags();
	
};


#endif