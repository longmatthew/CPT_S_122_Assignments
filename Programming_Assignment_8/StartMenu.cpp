#include "StartMenu.h"

void StartMenu::Show(sf::RenderWindow & renderWindow)
{
	sf::Texture splashTexture;
	splashTexture.loadFromFile("screen.png");
	
	sf::Sprite screenSprite;
	screenSprite.setTexture(splashTexture);

	MenuButton playIcon;
	playIcon.RectangleButton.top = 300;
	playIcon.RectangleButton.height = 200;
	playIcon.RectangleButton.left = 300;
	playIcon.RectangleButton.width = 200;
	playIcon.ButtonClick = Play;

	sf::RectangleShape rec1;
	rec1.setSize(sf::Vector2f(400, 150));
	rec1.setOutlineColor(sf::Color(255, 0, 0, 150));
	rec1.setFillColor(sf::Color(255, 255, 255, 100));
	rec1.setOutlineThickness(5);
	rec1.setPosition(50, 300);

	Playbutton.setString("Play!");
	Playbutton.setCharacterSize(30);
	Playbutton.setColor(sf::Color::White);
	Playbutton.setScale(1.f, 1.f);
	Playbutton.setPosition(400, 150);

	MenuButton exitIcon;
	exitIcon.RectangleButton.top = 700;
	exitIcon.RectangleButton.height = 200;
	exitIcon.RectangleButton.left = 700;
	exitIcon.RectangleButton.width = 200;
	exitIcon.ButtonClick = Exit;

	Exitbutton.setString("Exit");
	Exitbutton.setScale(50, 50);
	Exitbutton.setColor(sf::Color(150, 50, 50));
	Exitbutton.setPosition(70, 70);
	Exitbutton.setOrigin(200, 200);

	menuType.push_back(playIcon);
	menuType.push_back(exitIcon);

	sf::Event menuEvent;
	list<MenuButton>::iterator it;

	while (1)
	{
		// Looking for an action to occur in the main window that is created in Main.
		while (renderWindow.pollEvent(menuEvent))
		{
			// Waiting for input for a mouse button to be pressed.
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				// Need to iterate through the mouse clicks on the rectangle objects.
				for (it = menuType.begin(); it != menuType.end(); it++)
				{
					// Check to determine if click was within the bounds of the box to play the game or to exit.
					sf::Rect<int> menuRect = (*it).RectangleButton;
					if ((menuRect.top < menuEvent.mouseButton.y) && (menuRect.left < menuEvent.mouseButton.x))
					{
						if (playIcon.RectangleButton.contains(menuEvent.mouseMove.x, menuEvent.mouseMove.y))
						{
							Playbutton.setColor(sf::Color(250, 20, 20));
							if ((*it).ButtonClick == Play) // Open game and begin playing.
							{
								// Insert game mode here.
							}
						}
						else if (exitIcon.RectangleButton.contains(menuEvent.mouseMove.x, menuEvent.mouseMove.y))
						{
							Exitbutton.setColor(sf::Color(250, 20, 20));
							if ((*it).ButtonClick == Exit)  // Exit game.
							{
								renderWindow.close(); // Close the game.
							}
						}
					}
					else
					{
						(*it).ButtonClick == doNothing; // Not sure if this is even needed.
					}
				}
			}
			// Should the user press escape on the keyboard it will close the game.
			else if (menuEvent.KeyPressed == sf::Keyboard::Escape)
			{
				renderWindow.close(); // Close the window
			}
		}
		renderWindow.clear();
		renderWindow.draw(screenSprite);
		renderWindow.draw(rec1);
		renderWindow.draw(Playbutton);
		renderWindow.draw(Exitbutton);
		renderWindow.display();
	}
}

StartMenu::~StartMenu()
{

}
