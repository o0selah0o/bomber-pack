#ifndef __SCREEN_MULTI
#define __SCREEN_MULTI
#include <iostream>
#include "Screen.h"
 
class Screen_Multi : public Screen
{
public:
    Screen_Multi (void);
    virtual int Run (sf::RenderWindow &App, Model* _model, Controleur* _controleur);
};
#endif