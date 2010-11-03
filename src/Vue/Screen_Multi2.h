#ifndef __SCREEN_MULTI2
#define __SCREEN_MULTI2
#include <iostream>
#include <string>
#include "Screen.h"
 
class Screen_Multi2 : public Screen
{
private:
	std::string ip;
	bool isIn(int address, std::vector<std::pair<int,std::string> > list);
	
public:
    Screen_Multi2(std::string _ip);
    virtual int Run (sf::RenderWindow &App, Model* _model, Controleur* _controleur);
};
#endif