#ifndef __MAP
#define __MAP
#include "Node.h"
#include <String.h>
#include "Vehicle.h"

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
	private:
		std::vector<Vehicle*> vehicles;

	
};
#endif


