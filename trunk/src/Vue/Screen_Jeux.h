#ifndef __SCREEN_JEUX
#define __SCREEN_JEUX
#include <iostream>
#include "Screen.h"
 
/**
 * Ecran du jeu en mode solitaire
 */
class Screen_Jeux : public Screen
{
public:
    Screen_Jeux (void);
    virtual int Run (sf::RenderWindow &App, Model* _model, Controleur* _controleur);
};
#endif