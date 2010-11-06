#ifndef __SOLDIER
#define __SOLDIER
#include "Node.h"
#include <vector>
#include "Bullet.h"
#include "Vehicle.h"
/** 
 Sous classe de node, représentant un soldat **/


class Soldier: public Node
{
public:
	Soldier();
	~Soldier();
	Soldier(int _nujoueur,int _team,int _x,int _y);
	
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
	
	bool isActiv();
	
	int getNuJoueur();
	
	int getLife();
	
	void setLife(int _hp);
	
	
	bool isDead();
	int getTeam();
	
	float getSpeed();
	
	void setTeam(int t);
	
	
	void setNuJoueur(int nu);
	
	void setActiv(bool b);
	
	void hit(int damages);
	
	void enterVehicle(Vehicle* vehicle);
	
	void leaveVehicle();
	
	Vehicle* getVehicle();
	
	void setAngle(double degre);
	
	void setDead(bool val);
	
	double getAngle();
protected:
	// sa vitesse de déplacement
	float speed;
	// ses points de vie 
	int hp;
	//son équipe
	int team;
	
	bool activ;
	bool dead;
	int nujoueur;
	Vehicle* vehicleUti;
	double angle;
		
	
};


#endif