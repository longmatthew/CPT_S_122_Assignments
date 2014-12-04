#ifndef _START_MENU_
#define _START_MENU_

#include "AbstractMenu.h"

#include <string>
#include "SFML\Graphics.hpp"

class StartMenu : public AbstractMenu
{
	public:
		StartMenu(sf::RenderWindow * renderWindow);
		~StartMenu();

		int Display() = 0;
		void updateDisplay() = 0;
		int getMenuSelection() = 0;
		int mouseClick(int x, int y) = 0;

	private:
		MenuButton startGameButton;
		MenuButton exitGameButton;

		sf::Text GameTitle;
		sf::Text NewGame;
		sf::Text ExitGame;

};

#endif