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
	int i;
	for(i=0;i < (int)mappy.getChild().size(); i++) {
		printf("ELEMEN %c",mappy.getChild().at(i)->getSymbole());
	}
	char c;
	std::cin >> c;
	*/
	return 0;
	 
}

