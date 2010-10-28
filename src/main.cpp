#include "Vue/View.h"
#include <iostream>
#include <vector>
#include <string>
#include "math.h"

int main()
{
        std::cout << "Chargement de l'application" << std::endl;
        View* view = new View("","Fenetre principale", 640, 480);
        std::cout << "Lancement de l'application" << std::endl;
        view->Run();
        std::cout << "Destruction de l'application" << std::endl;
        return 0;
}

