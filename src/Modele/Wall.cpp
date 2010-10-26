#include "Wall.h"
#include "Node.h"

Wall::Wall(int _x, int _y, int longueur, int hauteur): Node(_x,_y,longueur,hauteur)
{
	symbole = 'w';
}