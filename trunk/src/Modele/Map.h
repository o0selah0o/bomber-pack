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
		Map();
		~Map();
		//méthode permettant de lire un fichier contenant les informations sur les noeuds à initialiser pour créer la map
		bool ReadFileMap(std::string fichier);
		bool ReadFileVehicles(std::string fichier);
		void addSpecificNode(int posx, int posy,int longueur,int hauteur,char type);
		bool ReadFileSoldiers(std::string fichier);
	void addSoldier(int coorx,int coory,char type, int team, int nujoueur );
	private:
		std::vector<Vehicle*> vehicles;
		std::vector<Soldier*> soldiers;
	
};
#endif


