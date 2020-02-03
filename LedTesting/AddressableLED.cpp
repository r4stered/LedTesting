#include "AddressableLED.h"

AddressableLED::AddressableLED(std::shared_ptr<sf::RenderWindow> window)
{
	windowPtr = window;
	RefreshList();
}

AddressableLED::AddressableLED() {
	windowPtr = nullptr;
}

void AddressableLED::SetData(const std::array<LedData, kStripLength>& ledData)
{
	for (int i = 0; i < kStripLength; i++) {
		ledStrip.at(i).setFillColor(sf::Color(ledData[i].GetR(), ledData[i].GetG(), ledData[i].GetB(), 255));
	}
}

void AddressableLED::DrawToScreen()
{
	for (int i = 0; i < kStripLength; i++) {
		windowPtr->draw(ledStrip[i]);
	}
}

void AddressableLED::RefreshList()
{
	int posX = 100;
	for (int i = 0; i < kStripLength; i++) {
		sf::RectangleShape led(sf::Vector2f(10, 10));
		led.setOutlineColor(sf::Color::White);
		led.setOutlineThickness(1);
		led.setPosition(sf::Vector2f(posX, 100));
		posX = posX + 20;
		ledStrip.at(i) = led;
	}
}
