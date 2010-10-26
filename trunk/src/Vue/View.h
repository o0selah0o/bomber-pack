#ifndef __SCREEN
#define __SCREEN
#include <SFML/Graphics.hpp>
#include "../Controller/Controleur.h"
#include "../Modele/Model.h"
#include <string>

class View
{
public:
	View(std::string _path, std::string _name, int _x, int _y);
	void Run();
	
private:
	Model* model;
	Controleur* controleur;
	std::string name;
	int x;
	int y;
};

#endif