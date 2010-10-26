#ifndef __NODE
#define __NODE
#include <vector>
#include <utility>
#include <string>
/**
 Classe modélisant un noeud dans l'arbre des éléments à afficher dans notre jeu.
 **/
class Node
{
public:
	Node();
	Node(int _x, int _y);
	Node(int _x, int _y, int _l, int _h);
	Node(int _x, int _y, int _l, int _h,char c_nom);
	~Node();
	
	void addChild(Node &rchild);
	void removeChild(int i);
	void setPosition(int _x, int _y);
	std::pair<int,int> getPosition();
	void setBoundingBox(int _h, int _l);
	std::pair<int,int> getBoundingBox();
	void setParent(Node* _parent);
	char getNodeAtPosXY(int _x,int _y);
	char getSymbole();
	std::vector< std::vector<int> >  cross(int x, int y, int dvue);
	
protected:
	Node* parent;
	std::vector<Node*> child;
	char symbole;
	int x;
	int y;
	int longueur;
	int hauteur;
	
};

#endif