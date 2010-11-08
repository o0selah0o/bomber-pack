#ifndef __MAP
#define __MAP
#include "Node.h"
#include <String.h>
#include "Vehicle.h"
#include "Soldier.h"

/**
 Classe représentant la map.
 **/
class Map:public Node
{
	public:
		//constructeur
		Map();
	
		//destructeur
		~Map();
	
		//méthode permettant de lire un fichier contenant les informations sur les noeuds à initialiser pour créer la map
		bool ReadFileMap(std::string fichier);
	
		//méthode permettant de lire le fichier contenant les véhicules
		bool ReadFileVehicles(std::string fichier);
	
		//méthode permettant de lire le fichier contenant les soldats
		bool ReadFileSoldiers(std::string fichier);
	
		//méthode ajoutant un noeud avec les paramètre nécessaire à la map
		void addSpecificNode(int posx, int posy,int longueur,int hauteur,char type);
	
		//méthode permettant d'ajouter un soldat à la map, avec les caractéristiques
		void addSoldier(int coorx,int coory,char type, int team, int nujoueur );
	
		//getter des soldats
		std::vector<Soldier*> getSoldiers();
	
		//getter des véhicules
		std::vector<Vehicle*> getVehicles(); 
		
	private:
		//tableau contenant les véhicules
		std::vector<Vehicle*> vehicles;
	
		//tableau contenant les soldats
		std::vector<Soldier*> soldiers;
	
};
#endif


