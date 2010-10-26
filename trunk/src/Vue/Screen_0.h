#ifndef __SCREEN_0
#define __SCREEN_0
#include <iostream>
#include "Screen.h"
 
class Screen_0 : public Screen
{
private:
    int alpha_max;
    int alpha_div;
    bool playing;
public:
    Screen_0 (void);
    virtual int Run (sf::RenderWindow &App, Model* _model, Controleur* _controleur);
};

#endif