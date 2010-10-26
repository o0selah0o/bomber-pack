#ifndef __VEHICLE__
#define __VEHICLE__
#include "Node.h"
/** 
 Sous classe de node, représentant un véhicule **/


class Vehicle: public Node
{
public:
	Vehicle();
	Vehicle(int _x, int _y, int longueur, int hauteur);
	~Vehicle();
	
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
	
	int getSpeed();
	
protected:
	// sa vitesse de déplacement
	int speed;
	// ses points de vie 
	int hp;
	
	
};


#endif