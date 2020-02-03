#include "LedSection.h"

LedSection::LedSection(int startLed, int endLed)
	: startIndex(startLed), endIndex(endLed) {
	currentPattern = std::make_unique<LedPattern>(LedPattern(GetLength()));
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

void LedSection::SetPattern(std::unique_ptr<LedPattern> pattern) {
	currentPattern = std::move(pattern);
}

const std::vector<LedData>& LedSection::GetCurrentBuffer() {
	return currentPattern->GetCurrentPattern();
}

void LedSection::Periodic() {
	currentPattern->Periodic();
}