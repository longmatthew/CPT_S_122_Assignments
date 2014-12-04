#ifndef _ABSTRACT_MENU_
#define _ABSTRACT_MENU_

#include <SFML\Graphics.hpp>

class AbstractMenu
{
	public:
		AbstractMenu();
		~AbstractMenu();
		virtual enum MenuSelection;

		struct MenuButton
		{
			sf::Rect<int> RectangleButton;
			MenuSelection ButtonClick;
		};

		virtual int Display() = 0;
		virtual void updateDisplay() = 0;
		virtual int getMenuSelection() = 0;
		virtual int mouseClick(int x, int y) = 0;
};

#endif
