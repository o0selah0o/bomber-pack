#ifndef __VIEW
#define __VIEW
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include "../Controller/Controleur.h"
#include "../Modele/Model.h"
#include <string>
#include <vector>
#include <iostream>

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