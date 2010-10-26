#ifndef __SCREEN_JEUX
#define __SCREEN_JEUX
#include <iostream>
#include "Screen.h"
 
class Screen_Jeux : public Screen
{
private:
    int movement_step;
    int posx;
    int posy;
    sf::Sprite Sprite;
public:
    Screen_Jeux (void);
    virtual int Run (sf::RenderWindow &App, Model* _model, Controleur* _controleur);
};
#endif