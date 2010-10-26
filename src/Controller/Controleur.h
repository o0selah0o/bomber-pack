#ifndef __CONTROLEUR
#define __CONTROLEUR
#include "../Modele/Model.h"
#include <string>
/**
 Classe modélisant le controleur du modele MVC applique a notre application
 **/
class Controleur
{
public: 
	Controleur(Model* _model);
	~Controleur();
	
	// Events
	void Event(std::string _action);
	void Event(std::string _action, int _dx, int _dy);
	
private:
	Model* model;

	
};

#endif