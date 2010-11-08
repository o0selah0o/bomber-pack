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

/**
 * Classe principale pour la vue
 * Elle gere l'application et l'initialisation de celle-ci
 */
class View
{
public:
	//Constructeur
	View(std::string _path, std::string _name, int _x, int _y);
	View(std::string _path, std::string _name);
	// La methode Run() permet de lancer l'application
	void Run();
	
private:
	// Le modele sera partager par toutes les vues
	Model* model;
	// Le controleur agit sur le modele en fonction des evenements
	Controleur* controleur;
	// Nom de la fenetre
	std::string name;
	// Largueur de la fenetre
	int x;
	// Hauteur de la fenetre
	int y;
	// Chemin vers le fichier contenant la carte principale
	std::string path;
	
};

#endif