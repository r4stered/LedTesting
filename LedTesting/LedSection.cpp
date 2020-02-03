#include "LedSection.h"

LedSection::LedSection(int startLed, int endLed, LedPattern pattern)
	: startIndex(startLed), endIndex(endLed), currentPattern(pattern) {
	for (int i = 0; i < endLed - startLed; i++) {
		currentBuffer.push_back(LedData(0.0, 0, 0));
	}
}

int LedSection::GetLastLedIndex() {
	return endIndex;
}

int LedSection::GetStartLedIndex() {
	return startIndex;
}

int LedSection::GetLength() {
	return endIndex - startIndex;
}

void LedSection::SetPattern(LedPattern pattern) {
	currentPattern = pattern;
}

const std::vector<LedData>& LedSection::GetCurrentBuffer() {
	return currentPattern.GetCurrentPattern();
}