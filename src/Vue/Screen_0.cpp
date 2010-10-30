#include "Screen_0.h"

Screen_0::Screen_0(std::string _path)
{
    alpha_max = 3*255;
    alpha_div = 3;
    playing = false;
	path = _path;
}

int Screen_0::Run (sf::RenderWindow &App, Model* _model, Controleur* _controleur)
{
    sf::Event Event;
    bool Running = true;
    sf::Image Image;
    sf::Sprite Sprite;
    int alpha = 0;
    sf::Font Font;
    sf::String Menu1;
    sf::String Menu2;
    sf::String Menu3;
    sf::String Menu4;
    sf::String Menu5;
    int menu = 2;
	
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
	
    Menu1.SetFont(Font);
    Menu1.SetSize(25);
    Menu1.SetText("Play");
    Menu1.SetX(App.GetView().GetRect().GetWidth() / 2 - 30);
    Menu1.SetY(App.GetView().GetRect().GetHeight() / 2 - 42);
    Menu2.SetFont(Font);
    Menu2.SetSize(25);
    Menu2.SetText("Exit");
    Menu2.SetX(App.GetView().GetRect().GetWidth() / 2 - 30);
    Menu2.SetY(App.GetView().GetRect().GetHeight() / 2 + 50);
    Menu3.SetFont(Font);
    Menu3.SetSize(25);
    Menu3.SetText("Continue");
    Menu3.SetX(App.GetView().GetRect().GetWidth() / 2 - 30);
    Menu3.SetY(App.GetView().GetRect().GetHeight() / 2 - 42);
	Menu4.SetFont(Font);
    Menu4.SetSize(25);
    Menu4.SetText("Restart");
    Menu4.SetX(App.GetView().GetRect().GetWidth() / 2 - 30);
    Menu4.SetY(App.GetView().GetRect().GetHeight() / 2);
	Menu5.SetFont(Font);
    Menu5.SetSize(25);
    Menu5.SetText("Multi-Player");
    Menu5.SetX(App.GetView().GetRect().GetWidth() / 2 - 30);
    Menu5.SetY(App.GetView().GetRect().GetHeight() / 2);
	
	App.Clear();
	
    if (playing)
    {
        alpha = alpha_max;
    }
	
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
                    case sf::Key::Return:
                        if (menu == 2)
                        {
							if(playing == false)
								playing = true;
                            return (1);
                        }
						if (menu == 1)
						{
							if(playing)
							{
								return 2;
							}
						}
                        else
                        {
                            return (-1);
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
            Menu3.SetColor(sf::Color(255, 0, 0, 255));
			Menu4.SetColor(sf::Color(0, 0, 0, 255));
			Menu5.SetColor(sf::Color(0, 0, 0, 255));
        }
		else if (menu == 1)
        {
            Menu1.SetColor(sf::Color(0, 0, 0, 255));
            Menu2.SetColor(sf::Color(0, 0, 0, 255));
            Menu3.SetColor(sf::Color(0, 0, 0, 255));
			Menu4.SetColor(sf::Color(255, 0, 0, 255));
			Menu5.SetColor(sf::Color(255, 0, 0, 255));
        }
        else
        {
            Menu1.SetColor(sf::Color(0, 0, 0, 255));
            Menu2.SetColor(sf::Color(255, 0, 0, 255));
            Menu3.SetColor(sf::Color(0, 0, 0, 255));
			Menu4.SetColor(sf::Color(0, 0, 0, 255));
			Menu5.SetColor(sf::Color(0, 0, 0, 255));
        }
		
        //Drawing
        App.Draw(Sprite);
		
		if (playing)
		{
			App.Draw(Menu3);
			App.Draw(Menu4); 
		}
		else
		{
			App.Draw(Menu1);
			App.Draw(Menu5);
		}
		App.Draw(Menu2);
		
        App.Display();
    }
	
    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}
