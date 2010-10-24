#include <vector>
#include "Node.h"
#include "math.h"
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
	symbole = 'z';
}

Node::Node(int _x, int _y, int _l, int _h)
{
	x = _x;
	y = _y;
	longueur = _l;
	hauteur = _h;
	symbole = 's';
}

Node::Node(int _x, int _y, int _l, int _h, std::string _nom)
{
	x = _x;
	y = _y;
	longueur = _l;
	hauteur = _h;
	c_nom = _nom;
}

Node::~Node()
{
	//ToDo
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

std::pair<int,int> Node::getBoundingBox()
{
	std::pair<int,int> p (hauteur, longueur); 
	
	return p;
}

void Node::setParent(Node* _parent)
{
	parent = _parent;
}

std::vector< std::vector<int> > Node::cross(int _x, int _y, int distanceVue)
{
	std::vector< std::vector<int> > res;
	std::vector<int> temp;
	temp.push_back(x);
	temp.push_back(y);
	temp.push_back(longueur);
	temp.push_back(hauteur);
	temp.push_back((int)symbole);
	res.push_back(temp);
	
	std::cout << "Cross : " << symbole << std::endl;
	
	int nbChild=child.size();
	int i;
	float nox;
	float sdEx;
	
	float noy;
	float sey;
	
	for (i=0; i < nbChild;i++)
	{
		nox=abs(_x - child.at(i)->x);
		sdEx=abs(_x  - (child.at(i)->x+ child.at(i)->longueur));
		
		noy=abs(_x - child.at(i)->x);
		sey=abs(_y - (child.at(i)->y - child.at(i)->hauteur));
		
		if(nox<=(distanceVue + _x) || noy<=(distanceVue+_y) || sdEx<=(distanceVue+_x) || sey<=(distanceVue+_y))
		{
			std::vector< std::vector<int> > vector2 = child.at(i)->cross(_x,_y,distanceVue);
			res.insert( res.end(), vector2.begin(), vector2.end() );
		}
	}
	
	
	return res;
}
