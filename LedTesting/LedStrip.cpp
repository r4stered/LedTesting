#include "LedStrip.h"
#include "SolidColorPattern.h"

LedStrip::LedStrip(std::shared_ptr<sf::RenderWindow> window) {
	leds = AddressableLED(window);
	ledBuffer.fill(LedData(1.0, .27, 0));
	leds.SetData(ledBuffer);
}

void LedStrip::AddSection(int subsectionLength) {
	if (sections.size() == 0) {
		sections.push_back(LedSection(0, subsectionLength, SolidColorPattern(frc::Color(0,0,0), subsectionLength)));
	}
	else {
		int startIdx = sections[sections.size() - 1].GetLastLedIndex();
		sections.push_back(LedSection(startIdx, startIdx + subsectionLength, SolidColorPattern(frc::Color(0, 0, 0), subsectionLength)));
	}
}

void LedStrip::FillBufferFromSections() {
	for (int i = 0; i < sections.size(); i++) {
		std::copy(sections[i].GetCurrentBuffer().begin(), sections[i].GetCurrentBuffer().end(), ledBuffer.begin() + sections[i].GetStartLedIndex());
	}
}

LedSection& LedStrip::GetSection(int idx) {
	return sections[idx];
}

void LedStrip::Periodic() {
	FillBufferFromSections();
	leds.SetData(ledBuffer);
	leds.DrawToScreen();
}