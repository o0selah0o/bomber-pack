#ifndef __NODE
#define __NODE
#include <vector>
#include <utility>
#include <string>

template <class T, class V> class bPair
{
public:
	bPair(T _first, V _second){first = _first; second = _second;};
	T first;
	V second;
};


/**
 Classe modélisant un noeud dans l'arbre des éléments à afficher dans notre jeu.
 **/
class Node
{
public:
	
	//constructeur
	Node();
	
	//constructeur avec coordonnées
	Node(int _x, int _y);
	
	//constructeur avec coordonnées et longueur/hauteur
	Node(int _x, int _y, int _l, int _h);
	
	//constructeur avec coordonnées , hauteur, longueur, symbole représentant le type du noeud
	Node(int _x, int _y, int _l, int _h,char c_nom);
	
	//destructeur
	~Node();
	
	//ajoute un noeud au tableau des enfants du noeud courant
	void addChild(Node &rchild);
	
	//enleve un noeud du tableau des enfants à la ième position
	void removeChild(int i);
	
	//défini la position du noeud vers les coordonnées x,y
	void setPosition(int _x, int _y);
	
	//getter des coordonnées du noeud
	bPair<int,int> getPosition();
	
	//défini la hauteur et la largeur du noeud
	void setBoundingBox(int _h, int _l);
	
	//recupère la hauteur et la largeur du noeud
	bPair<int,int> getBoundingBox();
	
	//défini le parend du noeud courants
	void setParent(Node* _parent);
	
	//donne le type de noeud qui se trouve à la position x, y dans le tableau des enfants du noeud
	Node* getNodeAtPosXY(int _x,int _y);
	
	//getter du symbole représentant le type du noeud
	char getSymbole();
	
	//méthode qui trie le graphe d'affichage avec ce que l'observateur voit. Non utile pour cette version du jeu
	std::vector< Node* >  cross(int x, int y, int hauteur,int longueur);
	
	//recupere les enfants du noeud courant
	std::vector<Node*> getChild();
	
	//effectue une rotation de la bouding box du noeud courant
	void rotate(int _angle);
	
	//récupère le centre x de la bouding box du noeud courant
	int getCenterX();
	
	//récupère le centre y de la bounding box du noeud courant
	int getCenterY();
	
	// Surcharge operateur
	bool operator==(const Node &_node);

	
protected:
	
	//pointeur sur le parent du noeud courant
	Node* parent;
	
	//tableau contenant les enfants du noeud courant
	std::vector<Node*> child;
	
	//symbole représentant le type du noeud courant
	char symbole;
	
	//composante x des coordonnées du noeud
	int x;
	
	//composante y des coordonnées du noeud
	int y;
	
	// longueur de la bounding box du noeud
	int longueur;
	
	//hauteur de la bounding box du noeud
	int hauteur;
	
};

#endif