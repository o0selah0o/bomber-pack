#ifndef __SCREEN_SELECT
#define __SCREEN_SELECT
#include <iostream>
#include <string>
#include "Screen.h"
 
/**
 * Ecran du role en multi-joueur
 */
class Screen_Select : public Screen
{
private:
    int alpha_max;
    int alpha_div;
    bool playing;
	std::string path;
	
public:
    Screen_Select();
    virtual int Run (sf::RenderWindow &App, Model* _model, Controleur* _controleur);
};

#endif