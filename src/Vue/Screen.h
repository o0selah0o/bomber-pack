#ifndef __SCREEN
#define __SCREEN
#include <SFML/Graphics.hpp>
#include "../Controller/Controleur.h"
#include "../Modele/Model.h"
#include <string>

class Screen
{
public :
    virtual int Run (sf::RenderWindow &App, Model* _model, Controleur* _controleur) = 0;
};

#endif
