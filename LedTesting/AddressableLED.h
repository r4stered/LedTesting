#pragma once

#include <initializer_list>
#include <array>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "LedData.h"
#include "Constants.h"

class AddressableLED
{
public:
	AddressableLED();
	AddressableLED(std::shared_ptr<sf::RenderWindow> window);
	void SetData(const std::array<LedData, kStripLength>& ledData);
	void DrawToScreen();
private:
	std::shared_ptr<sf::RenderWindow> windowPtr;
	void RefreshList();
	std::array<sf::RectangleShape, kStripLength> ledStrip;
};

