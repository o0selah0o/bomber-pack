#ifndef __SCREEN_0
#define __SCREEN_0
#include <iostream>
#include <string>
#include "Screen.h"
 
/**
 * Ecran des menus
 */ 
class Screen_0 : public Screen
{
private:
	// Pour afficher la selection du joueur
    int alpha_max;
    int alpha_div;
	// Permet de savoi si le jeu a deja ete lancer
    bool playing;
	std::string path;
	
public:
    Screen_0 (std::string _path);
    virtual int Run (sf::RenderWindow &App, Model* _model, Controleur* _controleur);
};

#endif