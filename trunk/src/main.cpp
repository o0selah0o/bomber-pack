#include "Vue/View.h"
#include <iostream>
#include <vector>
#include <string>
#include "math.h"


int main()
{	
	
	std::cout << "Chargement de l'application" << std::endl;
	View* view = new View("../../Images/map2","BattleField");
	std::cout << "Lancement de l'application" << std::endl;
	view->Run();
	std::cout << "Destruction de l'application" << std::endl;
	
	/*
	Model mod= Model("../../Images/map2");
	Map mappy= mod.getMap();
	std::vector<Vehicle*> vehicles = mod.getVehicles();
	int i;
	for(i=0;i < (int)vehicles.size(); i++) {
		printf("VEHICULE x=%c x=%i y=%i h=%i l=%i\n",vehicles.at(i)->getSymbole(),vehicles.at(i)->getPosition().first,vehicles.at(i)->getPosition().second,vehicles.at(i)->getBoundingBox().first,vehicles.at(i)->getBoundingBox().second);
	}
	char c;
	std::cin >> c;
	*/
	return 0;
	 
}

