#include <vector>
#include "Node.h"
#include "math.h"
#include "Map.h"
#include <iostream>
#include "Grass.h"
Node::Node()
{
	x = 0;
	y = 0;
}

Node::Node(int _x, int _y)
{
	x = _x;
	y = _y;
}

Node::Node(int _x, int _y, int _l, int _h)
{
	x = _x;
	y = _y;
	longueur = _l;
	hauteur = _h;
}

Node::Node(int _x, int _y, int _l, int _h,char _nom)
{
	x = _x;
	y = _y;
	longueur = _l;
	hauteur = _h;
	symbole = _nom;
}

Node::~Node()
{
	
	int i;
	int size= child.size();
	for (i=0; i<size; i++) {
		//delete(child.at(i));
	}
	 
}

void Node::addChild(Node &rchild)
{
	child.push_back(&rchild);
}

void Node::removeChild(int i)
{
	child.erase(child.begin() + 1);
}

void Node::setPosition(int _x, int _y)
{
	if(parent != NULL)
	{ 
		if (( _x >= (parent->getPosition().first) && _x <= (parent->getPosition().first + parent->getBoundingBox().first)) 
			&& ( _y >= (parent->getPosition().second) && _y <= (parent->getPosition().second + parent->getBoundingBox().second) )) 
		{
			x = _x;
			y = _y;
		}
	}
	else
	{
		x = _x;
		y = _y;
	}
}

std::pair<int,int> Node::getPosition()
{
	std::pair<int,int> p (x, y); 
	return p;
}

void Node::setBoundingBox(int _h, int _l)
{
	if(parent != NULL)
	{
		if(( (x + _h) >= (parent->getPosition().first) && (x + _h) <= (parent->getPosition().first + parent->getBoundingBox().first)) 
		   && ( (y + _l) >= (parent->getPosition().second) && (y + _l) <= (parent->getPosition().second + parent->getBoundingBox().second) )) 
		{
			hauteur = _h;
			longueur = _l;
		}
	}
	else
	{
		hauteur = _h;
		longueur = _l;
	}
	
}

char Node::getSymbole(){
	return symbole;
}
std::pair<int,int> Node::getBoundingBox()
{
	std::pair<int,int> p (hauteur, longueur); 
	
	return p;
}

void Node::setParent(Node* _parent)
{
	parent = _parent;
}

std::vector<Node*> Node::cross(int _x, int _y, int hauteur,int longueur)
{
	std::vector<Node*> res;
	int nbChild=child.size();
	int i;
	int xnoFov,ynoFov,xseFov,yseFov, xnoC,ynoC,xseC,yseC,xneC,yneC,xsoC,ysoC;
	
	xnoFov=_x-longueur;
	ynoFov=_y+hauteur;
	
	xseFov=_x+longueur;
	yseFov=_y-hauteur;
	
	
	for (i=0; i < nbChild;i++)
	{	
		char c=child.at(i)->getSymbole();
		if( c != 'g'){
			xnoC=child.at(i)->getPosition().first;
			ynoC=child.at(i)->getPosition().second + child.at(i)->getBoundingBox().first;
			
			xseC=child.at(i)->getPosition().first + child.at(i)->getBoundingBox().second;
			yseC=child.at(i)->getPosition().second ;
			
			xneC=child.at(i)->getPosition().first + child.at(i)->getBoundingBox().second;
			yneC=child.at(i)->getPosition().second + child.at(i)->getBoundingBox().first;
			
			xsoC=child.at(i)->getPosition().first;
			ysoC=child.at(i)->getPosition().second;
			
			if ( (xnoC > xnoFov  and ynoC < ynoFov and xnoC < xseFov and ynoC > yseFov) || (xneC > xnoFov  and yneC < ynoFov and xneC < xseFov and yneC > yseFov) || (xsoC > xnoFov  and ysoC < ynoFov and xsoC < xseFov and ysoC > yseFov) || (xseC > xnoFov  and yseC < ynoFov and xseC < xseFov and yseC > yseFov)) {
				res.push_back(child.at(i));
			}
		}
		else{
				res.push_back(child.at(i));
		}
			   
	}	
	return res;
}

Node* Node::getNodeAtPosXY(int _x,int _y){
	unsigned int i;
	unsigned int length= child.size();
	Node* res= new Grass();
	int xno,yno,xse,yse;
	for(i=0;i<length;i++){
		xno=child.at(i)->getPosition().first;
		yno=child.at(i)->getPosition().second;
		xse=child.at(i)->getPosition().first + child.at(i)->getBoundingBox().second;
		yse=child.at(i)->getPosition().second + child.at(i)->getBoundingBox().first;
		if( (xno) < _x and (yno) < _y and (xse) > _x and (yse) > _y and child.at(i)->getSymbole() != 'g'){
			res= child.at(i);
		}  
	}
	return res;
}


std::vector<Node*> Node::getChild(){
	return child;
}

