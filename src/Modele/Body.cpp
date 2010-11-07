#include "Body.h"
#include "Node.h"


Body::Body():Node(){
	symbole='x';
}
Body::Body(int _x, int _y): Node(_x,_y)
{
	symbole = 'x';
	longueur=40;
	hauteur=40;
}



Body::~Body(){
	
}