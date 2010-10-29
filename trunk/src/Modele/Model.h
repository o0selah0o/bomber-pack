

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
	
	bool moveUp(float coeff);
	bool moveBack(float coeff);
	bool moveRight(float coeff);
	bool moveLeft(float coeff);
	void update(float coeff);
	std::vector<Node*> FieldOfView(int _x,int _y,int hauteurfov,int longueurfov);
	std::vector<Projectile*> getProjectiles();

	
	

private:
	//Toute la carte de jeu. 
	Map wholeMap;
	//tableau contenant les personnages de la carte. Le premier est le joueur, le reste sont des bots
	std::vector<Soldier*> soldiers;
	// tableau contenant tous les vehicules de la carte
	std::vector<Vehicle*> vehicles;
	
	std::vector<Projectile*> projectiles;
	
};


#endif