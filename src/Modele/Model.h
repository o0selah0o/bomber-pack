#ifndef __MODEL
#define __MODEL

#include <vector>
#include "Node.h"
#include "Soldier.h"
#include "Vehicle.h"

/**
 Model a une map ( un arbre de nodes) et un vecteur de personnages
 **/
class Model:public Node
{
public:
	Model()
	~Model()
	// méthode qui séléctionne ce que voit le joueur
	std::vector<Node> FieldView();
	
	//getters and setters
	Node getWholeMap();
	std::vector<Soldiers> getSoldiers();
	std::vector<Vehicle> getVehicles()
	
	
	
	

private:
	//Toute la carte de jeu. 
	Node wholeMap;
	//tableau contenant les personnages de la carte. Le premier est le joueur, le reste sont des bots
	std::vector<Personnages> soldiers;
	// tableau contenant tous les vehicules de la carte
	std::vector<Vehicle> vehicles;
	
}

#endif