#pragma once

#include "Color.h"
#include "Color8Bit.h"

class LedData
{
public:
	LedData();
	LedData(double r, double g, double b);
	LedData(unsigned char r, unsigned char g, unsigned char b);
	void SetRGB(unsigned char r, unsigned char g, unsigned char b);
	void SetHSV(unsigned char h, unsigned char s, unsigned char v);
	void SetLed(const frc::Color& color);
	void SetLed(const frc::Color8Bit& color);
	unsigned char GetR() const;
	unsigned char GetG() const;
	unsigned char GetB() const;
private:
	unsigned char currentR;
	unsigned char currentG;
	unsigned char currentB;
};

