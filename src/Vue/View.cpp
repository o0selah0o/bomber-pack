#include "View.h"
#include "Screen.h"
#include "Screen_0.h"
#include "Screen_Jeux.h"


View::View(std::string _path, std::string _name, int _x, int _y)
{
	Model* _model = new Model(_path);
	model = _model;
	Controleur* _controleur = new Controleur(model);
	controleur = _controleur;
	name = _name;
	x = _x;
	y = _y;
}

View::View(std::string _path, std::string _name)
{
	Model* _model = new Model(_path);
	model = _model;
	Controleur* _controleur = new Controleur(model);
	controleur = _controleur;
	name = _name;
	x = model->getMap().getBoundingBox().first;
	y = model->getMap().getBoundingBox().second;
	path = _path;
}

void View::Run()
{
	//Applications variables
    std::vector<Screen*> screens;
    int screen = 0;
	
    //Window creation
    sf::RenderWindow App(sf::VideoMode(x, y, 32), name);
	
    //Mouse cursor no more visible
    //App.ShowMouseCursor(false);
	
    //Screens preparations
    Screen_0* s0 = new Screen_0(path);
    screens.push_back(s0);
    Screen_Jeux s1;
    screens.push_back(&s1);
	
    //Main loop
    while (screen >= 0)
    {
        screen = screens[screen]->Run(App,model,controleur);
		if(screen == 2)
		{
			model = new Model(path);
			controleur = new Controleur(model);
			screen = 1;
		}
    }
}