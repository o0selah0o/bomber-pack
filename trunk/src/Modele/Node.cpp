#include <vector>
#include "Node.h"
#include "math.h"
#include "Map.h"
#include <iostream>

Node::Node()
{
	x = 0;
	y = 0;
}

Node::Node(int _x, int _y)
{
	x = _x;
	y = _y;
	longueur = 0;
	hauteur = 0;
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
		delete(child.at(i));
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

std::vector<Node *> Node::cross(int _x, int _y, int hauteur,int longueur,Node* map)
{
	std::vector<Node *> res;
	int nbChild=child.size();
	int i;
	int xno,yno,xse,yse,xne,yne,xso,yso;
	xno=_x-longueur;
	yno=_y-hauteur;
	xso=_x-longueur;
	yso=_y-hauteur;
	xse=_x+longueur;
	yse=_y-hauteur;
	xne=_x+longueur;
	yne=_y+hauteur;
	
	for (i=0; i < nbChild;i++)
	{	
		
		/*if(nox<=(distanceVue + _x) || noy<=(distanceVue+_y) || sdEx<=(distanceVue+_x) || sey<=(distanceVue+_y))
		{
			std::vector< std::vector<int> > vector2 = child.at(i)->cross(_x,_y,distanceVue);
			res.insert( res.end(), vector2.begin(), vector2.end() );
		}*/
	}
	return res;
}

char Node::getNodeAtPosXY(int _x,int _y){
	unsigned int i;
	unsigned int length= child.size();
	char c= 'g';
	int xno,yno,xse,yse;
	for(i=0;i<length;i++){
		xno=child.at(i)->getPosition().first;
		yno=child.at(i)->getPosition().second;
		xse=child.at(i)->getPosition().first+ child.at(i)->getBoundingBox().second;
		yse=child.at(i)->getPosition().second + child.at(i)->getBoundingBox().first;
		if( (xno) < _x and (yno) < _y and (xse) > _x and (yse) > _y and child.at(i)->getSymbole() != 'g'){
			c= child.at(i)->getSymbole();
		}  
	}
	return c;
}


std::vector<Node*> Node::getChild(){
	return child;
}

