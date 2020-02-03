#pragma once

#include "LedPattern.h"
#include "LedData.h"
#include "Color.h"
#include <chrono>

class KnightRiderPattern : public LedPattern
{
public:
	KnightRiderPattern(frc::Color8Bit color, int sectionLength) : eyeColor(color), sectionSizePixels(sectionLength) ,LedPattern(sectionLength) {
		std::fill(buffer.begin(), buffer.end(), LedData(0.0, 0, 0.0));
	}
	~KnightRiderPattern() { }
	const std::vector<LedData>& GetCurrentPattern() {
		return LedPattern::buffer;
	}
	void Periodic() override {
		if (otherWay) {
			if (counterTwo > 0) {
				std::fill(buffer.begin(), buffer.end(), LedData(0.0, 0, 0.0));
				buffer[counterTwo].SetRGB(eyeColor.red, eyeColor.green, eyeColor.blue);
				for (int j = 1; j <= numOfPixelsForEye; j++) {
					buffer[counterTwo + j].SetRGB(eyeColor.red, eyeColor.green, eyeColor.blue);
				}
				buffer[counterTwo + numOfPixelsForEye + 1].SetRGB(eyeColor.red, eyeColor.green, eyeColor.blue);
				std::chrono::high_resolution_clock::time_point end_time = std::chrono::high_resolution_clock::now();
				auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
				if (dur.count() > speed) {
					start_time = std::chrono::high_resolution_clock::now();
					counterTwo--;
				}
			}
			else {
				counterTwo = (sectionSizePixels - numOfPixelsForEye - 2);
				otherWay = false;
			}
		}
		else {
			if (counterOne < (sectionSizePixels - numOfPixelsForEye - 2)) {
				std::fill(buffer.begin(), buffer.end(), LedData(0.0, 0, 0.0));
				buffer[counterOne].SetRGB(eyeColor.red, eyeColor.green, eyeColor.blue);
				for (int j = 1; j <= numOfPixelsForEye; j++) {
					buffer[counterOne + j].SetRGB(eyeColor.red, eyeColor.green, eyeColor.blue);
				}
				buffer[counterOne + numOfPixelsForEye + 1].SetRGB(eyeColor.red, eyeColor.green, eyeColor.blue);
				std::chrono::high_resolution_clock::time_point end_time = std::chrono::high_resolution_clock::now();
				auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
				if (dur.count() > speed) {
					start_time = std::chrono::high_resolution_clock::now();
					counterOne++;
				}
			}
			else {
				counterOne = 0;
				otherWay = true;
			}
		}
	}
private:
	std::chrono::high_resolution_clock::time_point start_time = std::chrono::high_resolution_clock::now();
	int speed = 100;
	bool otherWay = false;
	int counterOne = 0;
	int counterTwo = sectionSizePixels - numOfPixelsForEye - 2;
	int sectionSizePixels = 0;
	int numOfPixelsForEye = 1;
	frc::Color8Bit eyeColor;
};

