#pragma once

#include "LedPattern.h"
#include "LedData.h"
#include "Color.h"

class SolidColorPattern : public LedPattern
{
public:
	SolidColorPattern(frc::Color color, int sectionLength) : LedPattern(sectionLength) {
		std::fill(LedPattern::buffer.begin(), LedPattern::buffer.end(), LedData(color.red, color.green, color.blue));
	}
	~SolidColorPattern() {}
	const std::vector<LedData>& GetCurrentPattern() {
		return LedPattern::buffer;
	}
	void Periodic() {}
private:
	frc::Color currentColor;
};

