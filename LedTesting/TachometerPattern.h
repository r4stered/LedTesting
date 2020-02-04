#pragma once

#include "LedPattern.h"
#include "LedData.h"
#include "Color.h"

class TachometerPattern : public LedPattern
{
public:
	TachometerPattern(double speed, double maxSpeed, int sectionLength) : speedMulti(speed), maxSpeedScale(maxSpeed), LedPattern(sectionLength) {
		int idx = sectionLength + ((0.0 - sectionLength) / (maxSpeedScale - 0)) * (speedMulti - 0);
		std::vector<LedData> gradient;
		for (int i = 0; i < buffer.size(); i++) {
			int hue = 80 + ((0 - 80) / (sectionLength - 0)) * (i - 0);
			LedData rgb;
			rgb.SetHSV(hue, 255, 255);
			gradient.push_back(rgb);
		}
		std::copy(gradient.begin(), gradient.end() - idx, buffer.begin());
	}
	~TachometerPattern() { }
	const std::vector<LedData>& GetCurrentPattern() {
		return LedPattern::buffer;
	}
	void Periodic() override {
		
	}
private:
	double speedMulti = 0;
	double maxSpeedScale = 0;
	frc::Color8Bit fadeColor;
};

