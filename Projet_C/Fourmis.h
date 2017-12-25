#pragma once
#include "GraphicPrimitives.h"

class Fourmis {

public:
	Fourmis(float fx1, float fy1, float r = 0.5f, float g = 0.5f, float b = 0.5f, float a = 0.5f)
		:x1(fx1), y1(fy1),
		width(0.1f), height(0.1f),
		dx(0.01f), dy(0.02f),
		dw(0.01f), dh(-0.02f), r(r), g(g), b(b), a(a) {
		x2 = x1 + 0.1f;
		y2 = y1 + 0.05f;
		y3 = y3 = y1 + 0.1f;
		x3 = x1;
	}
	float x1, y1, x2, y2, x3, y3, width, height;

	// pos variation
	float dx;
	float dy;
	// size variation
	float dw;
	float dh;
	// color
	float r;
	float g;
	float b;
	float a;

	void draw();

};
