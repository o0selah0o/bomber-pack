

#ifndef __MODEL
#define __MODEL

#include <vector>
#include <string>
#include "Node.h"
#include "Soldier.h"
#include "Vehicle.h"
#include "Map.h"
#include "Projectile.h"

/**
 Model a une map ( un arbre de nodes) et un vecteur de personnages
 **/
class Model:public Node
{
public:
	Model();
	Model(std::string fichier);
	~Model();
	// méthode qui séléctionne ce que voit le joueur
	std::vector<Node> FieldView();
	
	//getters and setters
	Map getMap();
	std::vector<Soldier*> getSoldiers();
	std::vector<Vehicle*> getVehicles();
	
	bool moveUp(int i,float coeff);
	bool moveBack(int i,float coeff);
	bool moveRight(int i,float coeff);
	bool moveLeft(int i,float coeff);
	void update(float coeff);
	std::vector<Node*> FieldOfView(int _x,int _y,int hauteurfov,int longueurfov);
	std::vector<Projectile*> getProjectiles();
	void addProjectiles(Projectile* _projectile);
	void fire(int _dx,int _dy);
	
	

private:
	//Toute la carte de jeu. 
	Map wholeMap;
	//tableau contenant les personnages de la carte. Le premier est le joueur, le reste sont des bots
	std::vector<Soldier*> soldiers;
	// tableau contenant tous les vehicules de la carte
	std::vector<Vehicle*> vehicles;
	
	std::vector<Projectile*> projectiles;
	
	int lastFired;
};


#endif