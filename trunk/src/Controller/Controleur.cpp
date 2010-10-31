#include "Controleur.h"
#include <iostream>

Controleur::Controleur(Model* _model)
{
	model = _model;
}

Controleur::~Controleur()
{
	delete model;
}

// WARNING
// Must be done
void Controleur::Event(std::string _action, float Time)
{
	if(_action == "Up") 
	{
		model->moveUp(0,Time); 
	}
	if(_action == "Down") 
	{
		model->moveBack(0,Time);
	}
	if(_action == "Left")
	{
		model->moveLeft(0,Time);
	}
	if(_action == "Right")
	{
		model->moveRight(0,Time);
	}
	if(_action == "E")
	{
		// ToDo
	}
}

void Controleur::Event(std::string _action, int _dx, int _dy)
{
	if(_action == "lClick" and !model->getSoldiers().at(0)->isDead())
	{
		//model->getProjectiles().push_back(model->getSoldiers().at(0)->fire(_dx,_dy));
		model->fire(_dx,_dy,0);
 	}
	if(_action == "rClick")
	{
		//model->getVehicles().at(0)->
	}
}