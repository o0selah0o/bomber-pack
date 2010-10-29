#ifndef __SOLDIER
#define __SOLDIER
#include "Node.h"
#include <vector>
#include "Bullet.h"
/** 
 Sous classe de node, représentant un soldat **/


class Soldier: public Node
{
public:
	Soldier();
	~Soldier();
	Soldier(int _nujoueur,int _team,int _x,int _y);
	
	//fait avancer l'élément vers le Nord
	void moveUp(float coeff);
	//fait avancer l'élément vers le Sud
	void moveBack(float coeff);
	//fait avancer l'élément vers l'Ouest
	void moveLeft(float coeff);
	//fait avancer l'élément vers l'Est
	void moveRight(float coeff);
	//fait tirer un projectile à l'élément
	Bullet* fire(int _dx,int _dy);
	
	bool isActiv();
	
	int getNuJoueur();
	
	int getTeam();
	
	int getSpeed();
	
	void setTeam(int t);
	
	void setNuJoueur(int nu);
	
	void setActiv(bool b);
	
	void hit(int damages);
protected:
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