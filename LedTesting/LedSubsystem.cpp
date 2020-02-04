#include "LedSubsystem.h"

#include <iostream>
#include "SolidColorPattern.h"
#include "RainbowPattern.h"
#include "FadePattern.h"
#include "TachometerPattern.h"
#include "KnightRiderPattern.h"
#include "ChasePattern.h"

LedSubsystem::LedSubsystem(std::shared_ptr<sf::RenderWindow> window)
{
	ledStrip = LedStrip(window);
	ledStrip.AddSection(10);
	ledStrip.AddSection(10);
	ledStrip.AddSection(10);
	ledStrip.AddSection(10);
	ledStrip.AddSection(10);
}

void LedSubsystem::Periodic()
{
	ledStrip.Periodic();
}

void LedSubsystem::SetSectionToColor(int section, double r, double g, double b) {
	std::unique_ptr<LedPattern> pattern = std::make_unique<SolidColorPattern>(SolidColorPattern(frc::Color(r, g, b), ledStrip.GetSection(section).GetLength()));
	ledStrip.GetSection(section).SetPattern(std::move(pattern));
}

void LedSubsystem::SetSectionToFade(int section, double r, double g, double b) {
	std::unique_ptr<LedPattern> pattern = std::make_unique<FadePattern>(FadePattern(frc::Color(r, g, b), ledStrip.GetSection(section).GetLength()));
	ledStrip.GetSection(section).SetPattern(std::move(pattern));
}

void LedSubsystem::SetSectionToRainbow(int section) {
	std::unique_ptr<LedPattern> pattern = std::make_unique<RainbowPattern>(RainbowPattern(ledStrip.GetSection(section).GetLength()));
	ledStrip.GetSection(section).SetPattern(std::move(pattern));
}

void LedSubsystem::SetSectionToTachometer(int section, double speed, double maxSpeed) {
	std::unique_ptr<LedPattern> pattern = std::make_unique<TachometerPattern>(TachometerPattern(speed, maxSpeed, ledStrip.GetSection(section).GetLength()));
	ledStrip.GetSection(section).SetPattern(std::move(pattern));
}

void LedSubsystem::SetSectionToKnightRider(int section, double r, double g, double b) {
	std::unique_ptr<LedPattern> pattern = std::make_unique<KnightRiderPattern>(KnightRiderPattern(frc::Color(r, g, b), ledStrip.GetSection(section).GetLength()));
	ledStrip.GetSection(section).SetPattern(std::move(pattern));
}

void LedSubsystem::SetSectionToChase(int section, double r, double b, double g) {
	std::unique_ptr<LedPattern> pattern = std::make_unique<ChasePattern>(ChasePattern(frc::Color(r, g, b), ledStrip.GetSection(section).GetLength()));
	ledStrip.GetSection(section).SetPattern(std::move(pattern));
}