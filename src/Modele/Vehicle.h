#ifndef __VEHICLE
#define __VEHICLE
#include "Node.h"
/** 
 Sous classe de node, représentant un véhicule **/


public class Vehicle: public Node
{
public:
	Vehicle();
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
	
private:
	// sa vitesse de déplacement
	int speed;
	// ses points de vie 
	int hp;
	
	
}


#endif