#include "Screen_Jeux.h"

Screen_Jeux::Screen_Jeux (void)
{
}

int Screen_Jeux::Run (sf::RenderWindow &App, Model* _model, Controleur* _controleur)
{
    sf::Event Event;
    bool Running = true;
	
	sf::Image Image;
	
	if (!Image.LoadFromFile("../../Images/grass3.jpg"))
	{
		App.Close();
	}
	
	sf::Sprite Sprite;
	Sprite.SetImage(Image);
	Sprite.Scale(.35f,.37f);
	Sprite.SetPosition(0.f, 0.f);
	Sprite.SetCenter(App.GetView().GetRect().GetWidth() / 2 , App.GetView().GetRect().GetHeight() / 2);
	
	
	
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
		
		App.Draw(Sprite);
		
        //Drawing
		for(int i = 0; i < (int) _model->getSoldiers().size(); i++)
		{
			int x = (int)_model->getSoldiers().at(i)->getPosition().first;
			int y = (int) _model->getSoldiers().at(i)->getPosition().second;
			if(_model->getSoldiers().at(i)->getTeam() == 1)
				App.Draw(sf::Shape::Circle(x, y, 7, sf::Color::Green, 1, sf::Color::Black));
			if(_model->getSoldiers().at(i)->getTeam() == 2)
				App.Draw(sf::Shape::Circle(x, y, 7, sf::Color::Red, 1, sf::Color::Black));
			if(_model->getSoldiers().at(i)->getTeam() == 3)
				App.Draw(sf::Shape::Circle(x, y, 7, sf::Color::Black, 1, sf::Color::Black));
			if(_model->getSoldiers().at(i)->getTeam() == 4)
				App.Draw(sf::Shape::Circle(x, y, 7, sf::Color::Yellow, 1, sf::Color::Black));
		}
		
		for(int i = (int) _model->getProjectiles().size() - 1; i >= 0  ; i--)
			if(_model->getProjectiles().size() > 0)
				App.Draw(sf::Shape::Circle(_model->getProjectiles().at(i)->getPosition().first, _model->getProjectiles().at(i)->getPosition().second, 3, sf::Color::Blue, 1, sf::Color::Black));
		
		/*for(int i = 0; i < (int) _model->FieldView().size(); i++)
		{
			std::cout << "Symbole " << _model->FieldView().at(i).getSymbole() << std::endl;
		}*/
		
		App.Display();
    }
	
    //Never reaching this point normally, but just in case, exit the application
    return -1;
}
