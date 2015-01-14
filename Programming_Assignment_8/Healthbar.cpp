#include "HealthBar.h"

// Reference: http://sfmltd.codeplex.com/SourceControl/latest#TowerDefense/HealthBar.cpp

HealthBar::HealthBar()
{
	width = 30.0;
	height = 15.0;

	insideBar = sf::RectangleShape(sf::Vector2f(width, height)); // Creates a health bar within the outline of the health bar.
	insideBar.setFillColor(sf::Color(0, 255, 0, 200)); // Sets the color of the health bar on display
	insideBar.setOutlineThickness(4); // Sets the thickness or the disposition of the health bar
	insideBar.setOutlineColor(sf::Color(100, 150, 100, 100)); // Sets the color of that thickness.
}

HealthBar::~HealthBar()
{
	// Not using dynamic memory to set health bars.
}

HealthBar::HealthBar(float setWidth, float setHeight)
{
	// Assigning private variables to parameters.

	// Since the width will need to be greater than 0 a check is performed here.
	if (setWidth > 0)
	{
		width = setWidth;
	}

	// Since the height of the health bar needs to be greater than 0, a check is also performed here.
	if (setHeight > 0)
	{
		height = setHeight;
	}

	// To perform the shape of the rectangle the Rectangle needs to be positive or else the 
	// program will crash if anything negative is entered - we are also eliminating the chance of a zero enetered here.
	if (setWidth > 0 && setHeight > 0)
	{
		insideBar = sf::RectangleShape(sf::Vector2f(width, height));
		insideBar.setFillColor(sf::Color(0, 255, 0, 200));
		insideBar.setOutlineThickness(4);
		insideBar.setOutlineColor(sf::Color(100, 150, 100, 100));
	}
}

void HealthBar::DrawtoScreen(float xpos, float ypos, float percentage, sf::RenderTarget *renderTarget)
{
	insideBar.setScale(percentage, 1); // Sets the scale of the health bar according to enemy movement.
	insideBar.setPosition(xpos, ypos); // sets the position of the health bar according to enemy movement.
	renderTarget->draw(insideBar); // Draws the health bar onto the enemy target.
}
