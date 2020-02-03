#pragma once

#include "LedPattern.h"
#include <vector>
#include "LedData.h"
#include "SolidColorPattern.h"
class LedSection
{
public:
	LedSection(int startLed, int endLed, LedPattern pattern);
	int GetLastLedIndex();
	int GetStartLedIndex();
	int GetLength();
	void SetPattern(LedPattern pattern);
	const std::vector<LedData>& GetCurrentBuffer();
private:
	int startIndex = 0;
	int endIndex = 0;
	LedPattern currentPattern;
	std::vector<LedData> currentBuffer;
};

