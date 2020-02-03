#include "LedSubsystem.h"

#include <iostream>
#include "SolidColorPattern.h"

LedSubsystem::LedSubsystem(std::shared_ptr<sf::RenderWindow> window)
{
	ledStrip = LedStrip(window);
	ledStrip.AddSection(10);
	ledStrip.AddSection(10);
	ledStrip.AddSection(10);
	ledStrip.AddSection(10);
	ledStrip.AddSection(10);
	ledStrip.GetSection(2).SetPattern(SolidColorPattern(frc::Color(1, .67, 0), ledStrip.GetSection(2).GetLength()));
}

void LedSubsystem::Periodic()
{
	std::cout << "Periodic\n";
	ledStrip.Periodic();
}

void LedSubsystem::SetSectionToColor(int section, double r, double g, double b) {
	ledStrip.GetSection(section).SetPattern(SolidColorPattern(frc::Color(r, g, b), ledStrip.GetSection(section).GetLength()));
}
