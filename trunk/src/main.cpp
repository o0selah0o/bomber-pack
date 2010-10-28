#include "Vue/View.h"
#include <iostream>
#include <vector>
#include <string>
#include "math.h"
#include "Modele/Model.h"

int main()
{
		/*
        std::cout << "Chargement de l'application" << std::endl;
        View* view = new View("","Fenetre principale", 640, 480);
        std::cout << "Lancement de l'application" << std::endl;
        view->Run();
        std::cout << "Destruction de l'application" << std::endl;
		 */
		Model model= Model("../../Images/map1");
		Node map = model.getMap();
		std::vector<Soldier*> sol =model.getSoldiers();
		printf("taille de sol %d",(int)sol.size());
		char c;
		std::cin >> c;
        return 0;
}

