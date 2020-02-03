#pragma once

#include "LedPattern.h"
#include <vector>
#include "LedData.h"
#include "SolidColorPattern.h"
class LedSection
{
public:
	LedSection(int startLed, int endLed);
	int GetLastLedIndex();
	int GetStartLedIndex();
	int GetLength();
	void SetPattern(std::unique_ptr<LedPattern> pattern);
	const std::vector<LedData>& GetCurrentBuffer();
	void Periodic();
private:
	int startIndex = 0;
	int endIndex = 0;
	std::unique_ptr<LedPattern> currentPattern;
	std::vector<LedData> currentBuffer;
};

