#ifndef __GRASS__
#define __GRASS__
#include "Node.h"
/** 
 Sous classe de node, c'est une représentation d'un impact.
 **/


class Impact : public Node
{
	
public:
	//constructeur
	Impact();
	
	//constructeur avec coordonnées , hauteur, longueur et symbole représentant le type
	Impact(int _x, int _y, int longueur, int hauteur,char _symbole);
	
	//destructeur
	~Impact();
	
};


#endif