#include "LedData.h"

LedData::LedData() {
	currentR = 0;
	currentG = 0;
	currentB = 0;
}

LedData::LedData(double r, double g, double b) {
	currentR = r * 255;
	currentG = g * 255;
	currentB = b * 255;
}

LedData::LedData(unsigned char r, unsigned char g, unsigned char b) {
	currentR = r;
	currentG = g;
	currentB = b;
}

void LedData::SetRGB(unsigned char r, unsigned char g, unsigned char b) {
	currentR = r;
	currentG = g;
	currentB = b;
}

void LedData::SetHSV(unsigned char h, unsigned char s, unsigned char v) {
    if (s == 0) {
        SetRGB(v, v, v);
        return;
    }

    int region = h / 30;
    int remainder = (h - (region * 30)) * 6;

    int p = (v * (255 - s)) >> 8;
    int q = (v * (255 - ((s * remainder) >> 8))) >> 8;
    int t = (v * (255 - ((s * (255 - remainder)) >> 8))) >> 8;

    switch (region) {
    case 0:
        SetRGB(v, t, p);
        break;
    case 1:
        SetRGB(q, v, p);
        break;
    case 2:
        SetRGB(p, v, t);
        break;
    case 3:
        SetRGB(p, q, v);
        break;
    case 4:
        SetRGB(t, p, v);
        break;
    default:
        SetRGB(v, p, q);
        break;
    }
}

void LedData::SetLed(const frc::Color& color) {
	currentR = color.red * 255;
	currentG = color.green * 255;
	currentB = color.blue * 255;
}

void LedData::SetLed(const frc::Color8Bit& color) {
	currentR = color.red;
	currentG = color.green;
	currentB = color.blue;
}

unsigned char LedData::GetR() const
{
	return currentR;
}

unsigned char LedData::GetG() const
{
    return currentG;
}

unsigned char LedData::GetB() const
{
    return currentB;
}
