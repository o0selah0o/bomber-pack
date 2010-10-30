#include "Screen_Jeux.h"

Screen_Jeux::Screen_Jeux (void)
{
}

int Screen_Jeux::Run (sf::RenderWindow &App, Model* _model, Controleur* _controleur)
{
    sf::Event Event;
    bool Running = true;
	
	sf::Image grass;
	
	if (!grass.LoadFromFile("../../Images/grass3.jpg"))
	{
		App.Close();
	}
	
	sf::Sprite sGrass;
	sGrass.SetScale((App.GetView().GetRect().GetWidth() / 2400), (App.GetView().GetRect().GetHeight() / 1600));
	sGrass.SetImage(grass);
	
	sf::Image sand;
	
	if (!sand.LoadFromFile("../../Images/sand.jpg"))
	{
		App.Close();
	}
	
	sf::Image water;
	
	if (!water.LoadFromFile("../../Images/water.jpg"))
	{
		App.Close();
	}
	
	sf::Image beton;
	
	if (!beton.LoadFromFile("../../Images/beton.jpg"))
	{
		App.Close();
	}
	
	sf::Image plane;
	
	if (!plane.LoadFromFile("../../Images/aircraft.png"))
	{
		App.Close();
	}
	
	sf::Image jeep;
	
	if (!jeep.LoadFromFile("../../Images/jeep.png"))
	{
		App.Close();
	}
	
	sf::Image tank;
	
	if(!tank.LoadFromFile("../../Images/tankbox.png"))
	{
		App.Close();
	}
	
	
    while (Running)
    {
		float Time = App.GetFrameTime();
		unsigned int dx = App.GetInput().GetMouseX();
		unsigned int dy = App.GetInput().GetMouseY();
		//Key pressed			
		if (App.GetInput().IsKeyDown(sf::Key::Q)) _controleur->Event("Left",Time);
		if (App.GetInput().IsKeyDown(sf::Key::D)) _controleur->Event("Right",Time);
		if (App.GetInput().IsKeyDown(sf::Key::Z)) _controleur->Event("Up",Time);
		if (App.GetInput().IsKeyDown(sf::Key::S)) _controleur->Event("Down",Time);
		if (App.GetInput().IsKeyDown(sf::Key::Escape))  return 0;
		if (App.GetInput().IsMouseButtonDown(sf::Mouse::Left)) _controleur->Event("lClick",dx,dy);
		
        //Verifying events
        while (App.GetEvent(Event))
        {
            // Window closed
            if (Event.Type == sf::Event::Closed)
            {
                return (-1);
            }
			
        }
		
		
		//Clearing screen
		App.Clear();
		
		_model->update(Time);
		
		App.Draw(sGrass);
		
		// Affichage des textures que voit le soldat
		std::vector<Node*> vNode = _model->FieldOfView(0,0,App.GetView().GetRect().GetWidth(),App.GetView().GetRect().GetHeight());
		for(int i = 0; i < (int) vNode.size(); i++)
		{
			int x = vNode.at(i)->getPosition().first;
			int y = vNode.at(i)->getPosition().second;
			int h = vNode.at(i)->getBoundingBox().first;
			int l = vNode.at(i)->getBoundingBox().second;
			
			sf::Sprite temp;
			char symbol = vNode.at(i)->getSymbole(); 
			if(symbol != 'g')
			{
				std::cout << symbol << " at " << x << " , " << y << std::endl;
				switch (symbol) {
					case 'w':
						temp.SetImage(beton);
						break;
					case 's':
						temp.SetImage(sand);
						break;
					case 'a':
						temp.SetImage(water);
						break;
					default:
						break;
				}
				temp.Resize(l,h);
				temp.SetPosition(x-1,y);
			}
			
			
			App.Draw(temp);
			
		}
		
        //Affichage des soldats
		for(int i = 0; i < (int) _model->getSoldiers().size(); i++)
		{
			if(!_model->getSoldiers().at(i)->isDead())
			{
				int x = (int)_model->getSoldiers().at(i)->getPosition().first;
				int y = (int) _model->getSoldiers().at(i)->getPosition().second;
				
				switch (_model->getSoldiers().at(i)->getTeam()) {
					case 1:
						App.Draw(sf::Shape::Circle(x, y, 7, sf::Color::Green, 1, sf::Color::Black));
						break;
					case 2:
						App.Draw(sf::Shape::Circle(x, y, 7, sf::Color::Red, 1, sf::Color::Black));
						break;
					default:
						break;
				}
			}
		}
		
		//Affichage des balles
		for(int i = (int) _model->getProjectiles().size() - 1; i >= 0  ; i--)
			if(_model->getProjectiles().size() > 0)
				App.Draw(sf::Shape::Circle(_model->getProjectiles().at(i)->getPosition().first, _model->getProjectiles().at(i)->getPosition().second, 3, sf::Color::Blue, 1, sf::Color::Black));
		
		//Affichage des vehicules
		for(int i = (int) _model->getVehicles().size() - 1; i >= 0  ; i--)
		{
			int x = _model->getVehicles().at(i)->getPosition().first;
			int y = _model->getVehicles().at(i)->getPosition().second;
			int h = _model->getVehicles().at(i)->getBoundingBox().first;
			int l = _model->getVehicles().at(i)->getBoundingBox().second;
			
			sf::Sprite temp;
			char symbol = _model->getVehicles().at(i)->getSymbole(); 
			switch (symbol) {
				case 'j':
					temp.SetImage(jeep);
					break;
				case 'p':
					temp.SetImage(plane);
					break;
				case 't':
					temp.SetImage(tank);
					break;
				default:
					break;
			}
			temp.Resize(l,h);
			temp.SetPosition(x-1,y);
			
			
			App.Draw(temp);
			
		}
		
		App.Display();
    }
	
    //Never reaching this point normally, but just in case, exit the application
    return -1;
}