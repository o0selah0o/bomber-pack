#include "Screen_Select.h"
#include "Screen_Multi2.h"
#include <string>

Screen_Select::Screen_Select()
{
    alpha_max = 3*255;
    alpha_div = 3;
    playing = false;
}

int Screen_Select::Run (sf::RenderWindow &App, Model* _model, Controleur* _controleur)
{
    sf::Event Event;
    bool Running = true;
    sf::Image Image;
    sf::Sprite Sprite;
    int alpha = 0;
    sf::Font Font;
	sf::String Menu0;
    sf::String Menu1;
    sf::String Menu2;
    sf::String Menu3;
    sf::String Menu4;
    int menu = 2;
	std::string ip;
	
	sf::SoundBuffer Buffer;
	if (!Buffer.LoadFromFile("../../Images/theme.wav"))
	{
		std::cout << "Musique pas trouvée" << std::endl;
	}
	
	sf::Sound Sound;
	Sound.SetBuffer(Buffer); // Buffer est un sfSoundBuffer
	
    if (!Image.LoadFromFile("../../Images/bf2.jpg"))
    {
        std::cerr << "Error loading bf2.jpg" << std::endl;
        return (-1);
    }
	
	Sprite.SetScale((App.GetView().GetRect().GetWidth() / 500), (App.GetView().GetRect().GetHeight() / 375));
    Sprite.SetImage(Image);
	Sprite.SetPosition(-1,-1);
	
	if (!Font.LoadFromFile("../../Images/GUNPLA3D.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
    }
	
    Menu0.SetFont(Font);
    Menu0.SetSize(25);
    Menu0.SetText("Pour jouer en Client, tapez l'ip en remplacant les . de l'adresse par des ;");
    Menu0.SetX(30);
    Menu0.SetY(App.GetView().GetRect().GetHeight() / 2 - 120);
    Menu1.SetFont(Font);
    Menu1.SetSize(25);
    Menu1.SetText("Client");
    Menu1.SetX(App.GetView().GetRect().GetWidth() / 2 - 30);
    Menu1.SetY(App.GetView().GetRect().GetHeight() / 2 - 42);
    Menu2.SetFont(Font);
    Menu2.SetSize(25);
    Menu2.SetText("Serveur");
    Menu2.SetX(App.GetView().GetRect().GetWidth() / 2 - 30);
    Menu2.SetY(App.GetView().GetRect().GetHeight() / 2);
    Menu3.SetFont(Font);
    Menu3.SetSize(25);
    Menu3.SetText("Retour");
    Menu3.SetX(App.GetView().GetRect().GetWidth() / 2 - 30);
    Menu3.SetY(App.GetView().GetRect().GetHeight() / 2 + 100);
	Menu4.SetFont(Font);
    Menu4.SetSize(25);
    Menu4.SetText(ip);
    Menu4.SetX(App.GetView().GetRect().GetWidth() / 2 - 30);
    Menu4.SetY(App.GetView().GetRect().GetHeight() / 2 + 50);
	
	App.Clear();
	
    if (playing)
    {
        alpha = alpha_max;
    }
	
	Sound.Play();
	Sound.SetLoop(true);
	
    while (Running)
    {
		
        //Verifying events
        while (App.GetEvent(Event))
        {
            // Window closed
            if (Event.Type == sf::Event::Closed)
            {
                return (-1);
            }
            //Key pressed
            if (Event.Type == sf::Event::KeyPressed)
            {
                switch (Event.Key.Code)
                {
                    case sf::Key::Up:
						if(menu == 1)
							menu++;
						if(menu == 0)
							menu++;
                        break;
                    case sf::Key::Down:
						if(menu == 1)
							menu--;
						if(menu == 2)
							menu--;
                        break;
					case sf::Key::Num0 :
						ip = ip + "O";
						break;
					case sf::Key::Num1 :
						ip = ip + "1";
						break;
					case sf::Key::Num2 :
						ip = ip + "2";
						break;
					case sf::Key::Num3 :
						ip = ip + "3";
						break;
					case sf::Key::Num4 :
						ip = ip + "4";
						break;
					case sf::Key::Num5 :
						ip = ip + "5";
						break;
					case sf::Key::Num6 :
						ip = ip + "6";
						break;
					case sf::Key::Num7 :
						ip = ip + "7";
						break;
					case sf::Key::Num8 :
						ip = ip + "8";
						break;
					case sf::Key::Num9 :
						ip = ip + "9";
						break;
					case sf::Key::SemiColon :
						ip = ip + ".";
						break;
					case sf::Key::Back :
						if(ip.size() > 0)
							ip.erase(ip.end()-1);
						break;
                    case sf::Key::Return:
						Sound.Stop();
                        if (menu == 2)
                        {
							Screen_Multi2* s4 = new Screen_Multi2(ip);
							return (s4->Run(App,_model,_controleur));
                        }
						if (menu == 1)
						{
							//Serveur
							return 3;
						}
                        else
                        {
                            return 0;
                        }
                        break;
                    default :
                        break;
                }
            }
        }
        //When getting at alpha_max, we stop modifying the sprite
        if (alpha<alpha_max)
        {
            alpha++;
        }
        Sprite.SetColor(sf::Color(255, 255, 255, alpha/alpha_div));
        if (menu == 2)
        {
            Menu1.SetColor(sf::Color(255, 0, 0, 255));
            Menu2.SetColor(sf::Color(0, 0, 0, 255));
            Menu3.SetColor(sf::Color(0, 0, 0, 255));
        }
		else if (menu == 1)
        {
            Menu1.SetColor(sf::Color(0, 0, 0, 255));
            Menu2.SetColor(sf::Color(255, 0, 0, 255));
            Menu3.SetColor(sf::Color(0, 0, 0, 255));
        }
        else
        {
            Menu1.SetColor(sf::Color(0, 0, 0, 255));
            Menu2.SetColor(sf::Color(0, 0, 0, 255));
            Menu3.SetColor(sf::Color(255, 0, 0, 255));
        }
		
        //Drawing
        App.Draw(Sprite);
		Menu4.SetText(ip);
		App.Draw(Menu0);
		App.Draw(Menu3);
		App.Draw(Menu4); 
		App.Draw(Menu1);
		App.Draw(Menu2);
		
        App.Display();
    }
	
    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}
