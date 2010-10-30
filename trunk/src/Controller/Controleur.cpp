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
		model->getSoldiers().at(0)->moveUp(Time); 
	}
	if(_action == "Down") 
	{
		model->getSoldiers().at(0)->moveBack(Time);
	}
	if(_action == "Left")
	{
		model->getSoldiers().at(0)->moveLeft(Time);
	}
	if(_action == "Right")
	{
		model->getSoldiers().at(0)->moveRight(Time);
	}
	if(_action == "E")
	{
		// ToDo
	}
}

void Controleur::Event(std::string _action, int _dx, int _dy)
{
	if(_action == "lClick")
	{
		//model->getProjectiles().push_back(model->getSoldiers().at(0)->fire(_dx,_dy));
		model->addProjectiles(model->getSoldiers().at(0)->fire(_dx,_dy));
 	}
	if(_action == "rClick")
	{
		//model->getVehicles().at(0)->
	}
}