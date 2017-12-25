#pragma once
#include "GraphicPrimitives.h"

class Papillon {

public:
	Papillon(float fx = 0.0f, float fy = 0.0f, float r = 0.5f, float g = 0.5f, float b = 0.5f, float a = 0.5f)
		:x(fx), y(fy),
		width(0.1f), height(0.1f),
		dx(0.01f), dy(0.02f),
		dw(0.01f), dh(-0.02f), r(r), g(g), b(b), a(a) {
	}
	float x, y, width, height;

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
	void tick();

};
