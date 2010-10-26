#include "Screen_Jeux.h"

Screen_Jeux::Screen_Jeux (void)
{
    movement_step = 5;
    posx = 320;
    posy = 240;
    //Setting sprite
    Sprite.SetColor(sf::Color(255, 255, 255, 150));
    Sprite.SetSubRect(sf::IntRect(0, 0, 10, 10));
}
 
int Screen_Jeux::Run (sf::RenderWindow &App, Model* _model, Controleur* _controleur)
{
    sf::Event Event;
    bool Running = true;
 
 
    //Clearing screen
	App.Clear();
 
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
                    case sf::Key::Escape:
                        return (0);
                        break;
                    case sf::Key::Up:
                        posy -= movement_step;
                        break;
                    case sf::Key::Down:
                        posy += movement_step;
                        break;
                    case sf::Key::Left:
                        posx -= movement_step;
                        break;
                    case sf::Key::Right:
                        posx += movement_step;
                        break;
                    default:
                        break;
                }
            }
        }
 
        //Updating
        if (posx>630)
            posx = 630;
        if (posx<0)
            posx = 0;
        if (posy>470)
            posy = 470;
        if (posy<0)
            posy = 0;
        Sprite.SetPosition(posx, posy);
 
        //Drawing
        App.Draw(Sprite);
        App.Display();
    }
 
    //Never reaching this point normally, but just in case, exit the application
    return -1;
}
