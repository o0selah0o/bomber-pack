#include "Body.h"
#include "Node.h"


Body::Body():Node(){
	symbole='x';
}
Body::Body(int _x, int _y, int longueur, int hauteur,char _symbole): Node(_x,_y,longueur,hauteur)
{
	symbole = _symbole;
}



Body::~Body(){
	
}