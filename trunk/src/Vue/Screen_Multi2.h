#ifndef __SCREEN_MULTI2
#define __SCREEN_MULTI2
#include <iostream>
#include <string>
#include "Screen.h"
 
/**
 * Ecran client pour le multi-joueur
 */
class Screen_Multi2 : public Screen
{
private:
	// Ip du serveur ou client distant en mode ad-hoc
	std::string ip;
	// Verifie que le joueur est deja dans le modele
	bool isIn(int address, std::vector<std::pair<int,int> > list);
	
public:
    Screen_Multi2(std::string _ip);
    virtual int Run (sf::RenderWindow &App, Model* _model, Controleur* _controleur);
};
#endif