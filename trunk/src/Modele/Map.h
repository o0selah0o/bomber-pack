#ifndef __MAP
#define __MAP
#include "Node.h"
#include <String.h>

/**
 Classe représentant la map.
 **/
public class Map:public Node
{
	public:
		Map(std::string nom);
		~Map();
		//méthode permettant de lire un fichier contenant les informations sur les noeuds à initialiser pour créer la map
		bool ReadFile(std::string fichierCarte);
	
}
#endif