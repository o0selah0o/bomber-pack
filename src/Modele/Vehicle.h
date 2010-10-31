#ifndef __VEHICLE__
#define __VEHICLE__
#include "Node.h"
/** 
 Sous classe de node, représentant un véhicule **/


class Vehicle: public Node
{
public:
	Vehicle();
	Vehicle(int _x, int _y);
	Vehicle(int _x, int _y, int longueur, int hauteur);
	~Vehicle();
	
	//fait avancer l'élément vers le Nord
	void moveUp(float coeff,int h,int l);
	//fait avancer l'élément vers le Sud
	void moveBack(float coeff,int h,int l);
	//fait avancer l'élément vers l'Ouest
	void moveLeft(float coeff,int h,int l);
	//fait avancer l'élément vers l'Est
	void moveRight(float coeff,int h,int l);
	//fait tirer un projectile à l'élément
	void fire(int _dx,int _dy);
	
	void setUsed(bool used);
	bool isUsed();
	int getSpeed();
	void hit(int damages);
	bool isDestroyed();
	void setDestroyed(bool state);
	
protected:
	// sa vitesse de déplacement
	int speed;
	// ses points de vie 
	int hp;
	bool destroyed;
	bool used;
	
	
};


#endif