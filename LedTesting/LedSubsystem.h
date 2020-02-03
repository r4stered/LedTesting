#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <array>
#include "Constants.h"
#include "LedStrip.h"

class LedSubsystem
{
public:
	LedSubsystem(std::shared_ptr<sf::RenderWindow> window);
	void Periodic();
	void SetSectionToColor(int section, double r, double g, double b);
private:
	LedStrip ledStrip{ nullptr };
};

