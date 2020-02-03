#pragma once

#include "LedSection.h"
#include "AddressableLED.h"

class LedStrip
{
public:
	LedStrip(std::shared_ptr<sf::RenderWindow> window);
	void AddSection(int subsectionLength);
	void Periodic();
	LedSection& GetSection(int idx);
private:
	void FillBufferFromSections();
	std::vector<LedSection> sections;
	AddressableLED leds;
	std::array<LedData, kStripLength> ledBuffer;
};

