#include "Screen_Multi.h"
#include <SFML/Network.hpp>
#include <utility>
#include <sstream>

Screen_Multi::Screen_Multi (void)
{
}

bool Screen_Multi::isIn(sf::IPAddress address, std::vector<std::pair<sf::IPAddress,int> > list)
{
	if(list.size() < 1)
		return false;
	for(int i = 0; i < (int) list.size(); i++)
	{
		std::cout << "List : " << list.at(i).first << " Wanted " << address << std::endl;
		if(list.at(i).first == address)
			return true;
	}
	return false;
	
}

int Screen_Multi::Run (sf::RenderWindow &App, Model* _model, Controleur* _controleur)
{
    sf::Event Event;
    bool Running = true;
	sf::Font Font;
	std::vector<std::pair<sf::IPAddress,int> > listClient;
	// Création du socket UDP
	sf::SocketUDP Socket;
	sf::SocketUDP Socket2;
	Socket2.SetBlocking(false);
	// Your address in the local area network (like 192.168.1.100 -- the one you get with ipconfig)
	sf::IPAddress Address = sf::IPAddress::GetLocalAddress();
	
	int id = Address.ToInteger() % 10000 + sf::Randomizer::Random(1, 375);
	
	_model->getSoldiers().at(0)->setNuJoueur(id);
	
	int Random = sf::Randomizer::Random(1, 2);
	
	_model->getSoldiers().at(0)->setTeam(Random);
	
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
	
	sf::Image impact;
	
	if(!impact.LoadFromFile("../../Images/explosion.png"))
	{
		App.Close();
	}
	
	sf::Image smoke;
	
	if(!smoke.LoadFromFile("../../Images/impact.png"))
	{
		App.Close();
	}
	
	sf::Image hemo;
	
	if(!hemo.LoadFromFile("../../Images/blood.png"))
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
	sf::Clock ClockImpa;
	
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
		if (App.GetInput().IsKeyDown(sf::Key::Escape))  return 6;
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
		
		// On le lit au port 4567
		if (!Socket2.Bind(6000))
		{
			std::cout << "Not binding ;-) " << std::endl;
		}
		
		std::cout << "Binding if not not biding" << std::endl;
		
		char Buffer2[128];
		std::size_t Received;
		sf::IPAddress Sender;
		unsigned short Port;
		
		if(Socket2.Receive(Buffer2, sizeof(Buffer2), Received, Sender, Port) != sf::Socket::Done)
		{
			std::cout << "Pas reussi a recevoir de messages" << std::endl;
		}
		else 
		{
			int client = 0;
			
			std::string s;
			std::stringstream temp;
			temp << Buffer2;
			s = temp.str();
			
			std::string buf; // Have a buffer string
			std::stringstream ss(s); // Insert the string into a stream
			
			std::vector<std::string> tokens; // Create vector to hold our words
			std::cout << "Spliting the data" << std::endl;
			
			while (ss >> buf)
			{
				std::cout << buf << std::endl;
				tokens.push_back(buf);
			}
			if(tokens.size() > 1)
			{
				std::cout << "Data received - Size : " << tokens.size() << std::endl;
				client = atoi(tokens.at(0).c_str());
				std::cout << "Client : " << client << " mon num : " << _model->getSoldiers().at(0)->getNuJoueur() << std::endl;
				
				if(isIn(Sender,listClient))
				{
					std::cout << "Here nb soldier " << _model->getSoldiers().size() << std::endl;
					for(int i = 0; i < (int) _model->getSoldiers().size(); i++)
					{
						std::cout << _model->getSoldiers().at(i)->getNuJoueur() << std::endl;
						if(_model->getSoldiers().at(i)->getNuJoueur() == client)
						{
							if(client != _model->getSoldiers().at(0)->getNuJoueur())
							{
								std::cout << "Ici" << std::endl;
								int xtemp = atoi(tokens.at(1).c_str());
								int ytemp = atoi(tokens.at(2).c_str());
								std::cout << "X : " << xtemp << " Y : " << ytemp << std::endl;
								_model->getSoldiers().at(i)->setPosition(xtemp,ytemp);
								if(_model->getSoldiers().at(i)->getLife() > atoi(tokens.at(4).c_str()))
									_model->getSoldiers().at(i)->setLife(atoi(tokens.at(4).c_str()));
								_model->getSoldiers().at(i)->setDead((bool)(atoi(tokens.at(5).c_str())));
							}
							else 
							{
								std::cout << "Mise a jour de la vie" << std::endl;
								if(_model->getSoldiers().at(i)->getLife() > atoi(tokens.at(4).c_str()))
									_model->getSoldiers().at(i)->setLife(atoi(tokens.at(4).c_str()));
								_model->getSoldiers().at(i)->setDead((bool)(atoi(tokens.at(5).c_str())));
							}
							
						}
					}
				}
				else 
				{
					std::cout << "No Here" << std::endl;
					listClient.push_back(std::pair<sf::IPAddress,int>(Sender,(int)listClient.size()));
					_model->addSoldier(new Soldier(client,atoi(tokens.at(3).c_str()), atoi(tokens.at(1).c_str()), atoi(tokens.at(2).c_str())));
				}
			}
			
		}
		
		_model->update(Time);
		
		App.Draw(sGrass);
		
		// Affichage des textures que voit le soldat
		std::cout << "Texture" << std::endl;
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
		
		std::cout << "Soldat" << std::endl;
        //Affichage des soldats
		for(int i = 0; i < (int) _model->getSoldiers().size(); i++)
		{
			if(!_model->getSoldiers().at(i)->isDead() and _model->getSoldiers().at(i)->getLife() > 0)
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
		
		std::cout << "Gagnant" << std::endl;
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
		
		sf::String life;
		
		std::string lif;
		std::stringstream lifo;
		lifo << _model->getSoldiers().at(0)->getLife();
		lif = lifo.str(); 
		life.SetText(lif);
		life.SetFont(Font);
		life.SetSize(35);
		life.SetX(0);
		life.SetY(App.GetView().GetRect().GetHeight() - 50);
		life.SetColor(sf::Color(0, 0, 255, 255));
		App.Draw(life);
		
		//Affichage des balles
		std::cout << "Balles" << std::endl;
		for(int i = (int) _model->getProjectiles().size() - 1; i >= 0  ; i--)
			if(_model->getProjectiles().size() > 0)
				App.Draw(sf::Shape::Circle(_model->getProjectiles().at(i)->getPosition().first, _model->getProjectiles().at(i)->getPosition().second, 2, sf::Color::Black, 1, sf::Color::Black));
		
		//Affichage des Impacts
		for(int i = (int) _model->getImpacts().size() - 1; i >= 0  ; i--){
			if(_model->getImpacts().at(i)->getSymbole()== 's'){
				sf::Sprite im;
				im.SetImage(impact);
				im.SetCenter(230,200);
				im.SetPosition(_model->getImpacts().at(i)->getPosition().first,_model->getImpacts().at(i)->getPosition().second);
				im.Resize(_model->getImpacts().at(i)->getBoundingBox().first,_model->getImpacts().at(i)->getBoundingBox().second);
				App.Draw(im);
			}
			
			if(_model->getImpacts().at(i)->getSymbole()== 'i'){
				sf::Sprite im;
				im.SetImage(smoke);
				im.SetCenter(64,64);
				im.SetPosition(_model->getImpacts().at(i)->getPosition().first,_model->getImpacts().at(i)->getPosition().second);
				im.Resize(20,20);
				App.Draw(im);
			}
			if(_model->getImpacts().at(i)->getSymbole()== 'h'){
				sf::Sprite im;
				im.SetImage(hemo);
				im.SetCenter(64,64);
				im.SetPosition(_model->getImpacts().at(i)->getPosition().first,_model->getImpacts().at(i)->getPosition().second);
				im.Resize(20,20);
				App.Draw(im);
			}
		}
		float Time3 = ClockImpa.GetElapsedTime();
		if(Time3 > 0.5){
			_model->clearImpacts();
			ClockImpa.Reset();
		}
		
		App.Display();
		
		// Création du tableau d'octets à envoyer
		// ToDo : WARNING
		
		// Envoi des données à tous les clients sur le port 6000
		if(listClient.size() > 0)
		{
			for(int i = 0; i < (int)_model->getSoldiers().size(); i++)
			{
				
				std::string s;
				std::stringstream out;
				out << _model->getSoldiers().at(i)->getNuJoueur() << ' ';
				out << _model->getSoldiers().at(i)->getPosition().first << ' ';
				out << _model->getSoldiers().at(i)->getPosition().second << ' ';
				out << _model->getSoldiers().at(i)->getTeam() << ' ';
				out << _model->getSoldiers().at(i)->getLife() << ' ';
				out << (int)(_model->getSoldiers().at(i)->isDead()); 
				s = out.str();
				
				char* Buffer = (char*)s.c_str();
				
				for(int j = 0; j < (int) listClient.size(); j++)
				{
					if (Socket.Send(Buffer, 128, listClient.at(j).first.ToString(), 6000) != sf::Socket::Done)
					{
						std::cout << "Souci non ?" << std::endl;
					}
				}
			}
		}
    }
	
    //Never reaching this point normally, but just in case, exit the application
    return -1;
}
