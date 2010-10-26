#include "Controleur.h"

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
void Controleur::Event(std::string _action)
{
	if(_action == "Up") 
	{
		model->getSoldiers().at(0)->moveUp(); 
	}
	if(_action == "Down") 
	{
		model->getSoldiers().at(0)->moveBack();
	}
	if(_action == "Left")
	{
		model->getSoldiers().at(0)->moveLeft();
	}
	if(_action == "Right")
	{
		model->getSoldiers().at(0)->moveRight();
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
		model->getSoldiers().at(0)->fire(_dx,_dy);
	}
	if(_action == "rClick")
	{
		//model->getVehicles().at(0)->
	}
}