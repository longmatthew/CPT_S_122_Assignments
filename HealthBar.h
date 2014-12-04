#ifndef _HEALTH_BAR_ // Header 'Lock'
#define _HEALTH_BAR_

// Reference: http://sfmltd.codeplex.com/SourceControl/latest#TowerDefense/HealthBar.h

// Inclusion of preprocessor directives and libraries.
#include <SFML\Graphics.hpp>

class HealthBar
{
	public:
		HealthBar(); // Constructor
		~HealthBar(); // Destructor

		HealthBar(float setWidth, float setHeight); // Initializer Constructor

		// Function to draw object to rendered screen
		void DrawtoScreen(float xpos, float ypos, float percentage, sf::RenderTarget *renderTarget);
	private:
		float width;
		float height;
		sf::RectangleShape insideBar;
};

#endif // End of 'Lock'