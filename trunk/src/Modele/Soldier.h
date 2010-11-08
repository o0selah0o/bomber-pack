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
	//constructeur
	Soldier();
	
	//destructeur
	~Soldier();
	
	//constructeur avec identifiant, équipe et coordonnées d'apparition
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
	
	//getter d'activ
	bool isActiv();
	
	//getter d'identifiant
	int getNuJoueur();
	
	//getter des points de vie
	int getLife();
	
	//setter des points de vie
	void setLife(int _hp);
	
	//getter de dead
	bool isDead();
	
	//getter de l'équipe
	int getTeam();
	
	//getter de speed
	float getSpeed();
	
	//setter de l'équipe
	void setTeam(int t);
	
	//set de l'identifiant
	void setNuJoueur(int nu);
	
	//setter d'activ
	void setActiv(bool b);
	
	//méthode infligeant des dégats au joueur
	void hit(int damages);
	
	//méthode permettant d'entrer dans un véhicule
	void enterVehicle(Vehicle* vehicle);
	
	//méthode permettant de quitter un véhicule
	void leaveVehicle();
	
	//getter du véhicule utilisé
	Vehicle* getVehicle();
	
	//setter de l'angle
	void setAngle(double degre);
	
	//setter de dead
	void setDead(bool val);
	
	//getter de l'angle
	double getAngle();
protected:
	// sa vitesse de déplacement
	float speed;
	
	// ses points de vie 
	int hp;
	
	//son équipe
	int team;
	
	//détermine si le soldat est actif ou non
	bool activ;
	
	//détermine si le soldat est mort ou non
	bool dead;
	
	//identifiant du soldat
	int nujoueur;
	
	//pointeur sur le véhicule utilisé par le soldat
	Vehicle* vehicleUti;
	
	//angle qui détermine la direction dans laquelle regarde le soldat
	double angle;
		
	
};


#endif