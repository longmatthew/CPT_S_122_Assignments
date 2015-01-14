#ifndef _START_MENU_
#define _START_MENU_

#include "TotalHeaderFile.h"

class StartMenu
{
	public:
		void Show(sf::RenderWindow &renderWindow);
		~StartMenu();
		enum MenuSelection { doNothing, Exit, Play };

		struct MenuButton
		{
			public:
				sf::Rect<int> RectangleButton;
				MenuSelection ButtonClick;
		};

	private:
		list<MenuButton> menuType;
		sf::Text Playbutton;
		sf::Text Exitbutton;
};

#endif
