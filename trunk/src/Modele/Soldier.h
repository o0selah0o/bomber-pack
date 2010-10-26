#ifndef __SOLDIER
#define __SOLDIER
#include "Node.h"
#include <vector>
/** 
 Sous classe de node, représentant un soldat **/


class Soldier: public Node
{
public:
	Soldier();
	~Soldier();
	Soldier(int _nujoueur,int _team,int _x,int _y);
	
	//fait avancer l'élément vers le Nord
	void moveUp();
	//fait avancer l'élément vers le Sud
	void moveBack();
	//fait avancer l'élément vers l'Ouest
	void moveLeft();
	//fait avancer l'élément vers l'Est
	void moveRight();
	//fait tirer un projectile à l'élément
	void fire(int _dx,int _dy);
	
	bool isActiv();
	
	int getNuJoueur();
	
	int getTeam();
	
	int getSpeed();
	
	void setTeam(int t);
	
	void setNuJoueur(int nu);
	
	void setActiv(bool b);
	
private:
	// sa vitesse de déplacement
	int speed;
	// ses points de vie 
	int hp;
	//son équipe
	int team;
	
	bool activ;
	
	int nujoueur;
		
	
};


#endif