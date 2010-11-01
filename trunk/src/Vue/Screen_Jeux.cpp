#include "Screen_Jeux.h"

Screen_Jeux::Screen_Jeux (void)
{
}

int Screen_Jeux::Run (sf::RenderWindow &App, Model* _model, Controleur* _controleur)
{
    sf::Event Event;
    bool Running = true;
	sf::Font Font;
	
	if (!Font.LoadFromFile("../../Images/GUNPLA3D.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
    }
	
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
	
	if(!tank.LoadFromFile("../../Images/tBox.png"))
	{
		App.Close();
	}
	
	sf::Image soldier;
	
	if(!soldier.LoadFromFile("../../Images/soldier.png"))
	{
		App.Close();
	}
	
	sf::Image soldier2;
	
	if(!soldier2.LoadFromFile("../../Images/soldier2.png"))
	{
		App.Close();
	}
	
	sf::SoundBuffer Buffer;
	if (!Buffer.LoadFromFile("../../Images/bar.wav"))
	{
		std::cout << "Musique pas trouvée" << std::endl;
	}
	
	sf::Sound Sound;
	Sound.SetBuffer(Buffer); // Buffer est un sfSoundBuffer
	
	sf::Clock Clock;
	
    while (Running)
    {
		float Time = App.GetFrameTime();
		float Time2 = Clock.GetElapsedTime();
		
		unsigned int dx = App.GetInput().GetMouseX();
		unsigned int dy = App.GetInput().GetMouseY();
		
		//Key pressed			
		if (App.GetInput().IsKeyDown(sf::Key::Q)) _controleur->Event("Left",Time);
		if (App.GetInput().IsKeyDown(sf::Key::D)) _controleur->Event("Right",Time);
		if (App.GetInput().IsKeyDown(sf::Key::Z)) _controleur->Event("Up",Time);
		if (App.GetInput().IsKeyDown(sf::Key::S)) _controleur->Event("Down",Time);
		if (App.GetInput().IsKeyDown(sf::Key::E)) _controleur->Event("E",Time);
		if (App.GetInput().IsKeyDown(sf::Key::Escape))  return 0;
		if (App.GetInput().IsMouseButtonDown(sf::Mouse::Left)) _controleur->Event("lClick",dx,dy);
		if (App.GetInput().IsMouseButtonDown(sf::Mouse::Left) and Time2 >= 0.5)
		{
			Sound.Play();
			Clock.Reset();
		}
		
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
		//std::cout << "Texture" << std::endl;
		std::vector<Node*> vNode = _model->getMap().getChild();
		
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
				App.Draw(temp);
			}
		}
		
		int cpt_rouge = 0;
		int cpt_vert = 0;
		
		//std::cout << "Soldat" << std::endl;
        //Affichage des soldats
		for(int i = 0; i < (int) _model->getSoldiers().size(); i++)
		{
			if(!_model->getSoldiers().at(i)->isDead() and _model->getSoldiers().at(i)->isActiv())
			{
				int x = (int)_model->getSoldiers().at(i)->getPosition().first;
				int y = (int) _model->getSoldiers().at(i)->getPosition().second;
				
				sf::Sprite temp;
				temp.SetPosition(x,y);
				switch (_model->getSoldiers().at(i)->getTeam()) {
					case 1:
						//App.Draw(sf::Shape::Circle(x, y, 7, sf::Color::Green, 1, sf::Color::Black));
						cpt_vert++;
						temp.SetImage(soldier);
						break;
					case 2:
						//App.Draw(sf::Shape::Circle(x, y, 7, sf::Color::Red, 1, sf::Color::Black));
						temp.SetImage(soldier2);
						cpt_rouge++;
						break;
					default:
						break;
				}
				temp.Resize(25, 25);
				
				if(i == 0)
				{
					float angle = atan2(temp.GetPosition().y - dy, temp.GetPosition().x - dx) * 180 / 3.14;	
					temp.SetCenter(25,25);
					temp.SetRotation(-angle + 90);	
				}
				
				App.Draw(temp);
			}
		}
		
		sf::String game;
		if(cpt_vert == 0)
		{
			game.SetText("Team 2 - Win");
		}
		else if(cpt_rouge == 0)
		{
			game.SetText("Team 1 - Win");
		}
		
		game.SetFont(Font);
		game.SetSize(45);
		game.SetX(App.GetView().GetRect().GetWidth() / 2 - 50);
		game.SetY(App.GetView().GetRect().GetHeight() / 2 + 50);
		game.SetColor(sf::Color(0, 0, 0, 255));
		App.Draw(game);
		
		//Affichage des balles
		for(int i = (int) _model->getProjectiles().size() - 1; i >= 0  ; i--)
			if(_model->getProjectiles().size() > 0)
				App.Draw(sf::Shape::Circle(_model->getProjectiles().at(i)->getPosition().first, _model->getProjectiles().at(i)->getPosition().second, 2, sf::Color::Black, 1, sf::Color::Black));
		
		//Affichage des vehicules
		for(int i = (int) _model->getVehicles().size() - 1; i >= 0  ; i--)
		{
			int x = _model->getVehicles().at(i)->getPosition().first;
			int y = _model->getVehicles().at(i)->getPosition().second;
			int l = _model->getVehicles().at(i)->getBoundingBox().first;
			int h = _model->getVehicles().at(i)->getBoundingBox().second;
			
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
			//std::cout << "Vehicules " << symbol << " : " << h << " " << l << std::endl;
			temp.Resize(h,l);
			temp.SetPosition(x-1,y);
			temp.SetRotation(_model->getVehicles().at(i)->getAngle());
			
			App.Draw(temp);
			
		}
		
		App.Display();
    }
	
    //Never reaching this point normally, but just in case, exit the application
    return -1;
}
