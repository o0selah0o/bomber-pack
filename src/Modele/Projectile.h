#ifndef __PROJECTILE
#define __PROJECTILE
#include "Node.h"

/**
 Classe modélisant un projectile
 **/

class Projectile: public Node
{
public:
	//constructeur
	Projectile();
	
	//constructeur avec coordonnées de départ et coordonnées d'arrivée
	Projectile(int _x,int _y,int _dx,int _dy);
	
	//destructeur
	~Projectile();
	
	//fonction qui déplace la balle
	void parcourir(float coeff);
	
	//Getters and Setters
	
	//getter de la vitesse
	int getSpeed();
	
	//getter de la portée
	int getRange();
	
	//getter de la puissance
	int getPower();
	
	//getter du x de la destination
	int getDx();
	
	//getter du y de la destination
	int getDy();
	
	//getter de la droite déterminant la trajectoire du projectile
	std::pair<double,double> getTrajectoryAB();
	
	//getter de la distance parcourue par le projectile
	int getParcouru();


	
protected:
	// les coordonnées de la direction dans laquelle va le projectile.
	int dx;
	int dy;
	// la portée du projectile
	int range;
	//la vitesse du projectile
	double speed;
	// la puissance du projectile : le nombre de points de vie qu'il enlève
	int power;
	
	//la distance parcouru par le projectile depuis sa "mise à feu"
	int parcouru;
	
	//facteur de deplacement
	double facteur;

	
	
};
#endif