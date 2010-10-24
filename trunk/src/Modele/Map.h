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
		bool ReadFile(std::string fichierCarte);
	
	private:
		std::string nom
		
		
		
	
}
#endif