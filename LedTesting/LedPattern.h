#pragma once

#include <vector>
#include "LedData.h"

class LedPattern
{
public:
	LedPattern(int sectionLength) : size(sectionLength) {
		buffer.resize(size);
	}
	~LedPattern() {}
	const std::vector<LedData>& GetCurrentPattern() {
		return buffer;
	}
	void Periodic();
protected:
	int size = 0;
	std::vector<LedData> buffer;
};

