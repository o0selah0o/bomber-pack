#ifndef __VEHICLE__
#define __VEHICLE__
#include "Node.h"
#include "Projectile.h"
/** 
 Sous classe de node, représentant un véhicule **/


class Vehicle: public Node
{
public:
	
	//constructeur
	Vehicle();
	
	//constructeur avec coordonnées d'apparition
	Vehicle(int _x, int _y);
	
	//constructeur avec coordonnées d'apparition, longueur,hauteur
	Vehicle(int _x, int _y, int longueur, int hauteur);
	
	//destructeur
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
	Projectile* fire(int _dx,int _dy);
	
	//setter du champs used
	void setUsed(bool used);
	
	//getter du champs used
	bool isUsed();
	
	//getter de la vitesse
	int getSpeed();
	
	//inflige des degats
	void hit(int damages);
	
	//getter du statut detruit
	bool isDestroyed();
	
	//setter du statut detruit
	void setDestroyed(bool state);
	
	//getter de l'angle
	double getAngle();
	
protected:
	// sa vitesse de déplacement
	int speed;
	
	// ses points de vie 
	int hp;
	
	//statut du detruction
	bool destroyed;
	
	//statut d'occupation par un soldat
	bool used;
	
	//angle d'orientation du vehicule
	double angle;
	
	//angle d'orientation précédent
	double anglePrec;
	
	
};


#endif