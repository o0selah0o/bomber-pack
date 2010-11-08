#ifndef __SCREEN_MULTI
#define __SCREEN_MULTI
#include <iostream>
#include "Screen.h"
 
/**
 * Ecran du serveur pour le multijoueur
 */
class Screen_Multi : public Screen
{
private:
	// Verifie qu'une adresse d'un client est dans la liste de clients
	bool isIn(sf::IPAddress address, std::vector<std::pair<sf::IPAddress,int> > list);
	
public:
    Screen_Multi (void);
    virtual int Run (sf::RenderWindow &App, Model* _model, Controleur* _controleur);
};
#endif