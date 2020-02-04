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
	void SetSectionToRainbow(int section);
	void SetSectionToFade(int section, double r, double g, double b);
	void SetSectionToTachometer(int section, double speed, double maxSpeed);
	void SetSectionToKnightRider(int section, double r, double g, double b);
	void SetSectionToChase(int section, double r, double b, double g);
private:
	LedStrip ledStrip{ nullptr };
};

