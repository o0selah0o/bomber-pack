#ifndef __MODEL
#define __MODEL

#include <vector>
#include "Node.h"
/**
 Model a une map ( un arbre de nodes) et un vecteur de personnages
 **/
class Model:public Node
{
public:
	Model()
	~Model()
	

private:
	std::vector<Personnages> personnages
	
}

#endif