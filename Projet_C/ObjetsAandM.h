#pragma once
#include "GraphicPrimitives.h"

class ObjetsAandM {

public:
	ObjetsAandM(float fx1, float fy1, int vitesse, unsigned long start, int id, int mult = 1, float r = 0.5f, float g = 0.5f, float b = 0.5f, float a = 0.5f)
		:x1(fx1), y1(fy1), r(r), g(g), b(b), a(a), start(start), id(id), vitesse(vitesse / 2) {
		listeX = creaListeX(fx1, mult);
		listeY = creaListeY(fy1, mult);
	}

	float x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8;
	std::vector<float> listeX;
	std::vector<float> listeY;

	//vitesse
	int vitesse;

	//startTime
	unsigned long start;

	//liste missile et asteroide
	int id;

	// color
	float r;
	float g;
	float b;
	float a;

	float getX() {
		return listeX[0];
	}
	float getY() {
		return listeY[0];
	}

	static std::vector<float> creaListeX(float x1, int mult) {
		std::vector<float> l;
		float x2, x3, x4, x5, x6;
		x2 = x1 + 0.01f * mult;
		x3 = x2 + 0.03f * mult;
		x4 = x1 + 0.05f * mult;
		x5 = x3;
		x6 = x2;

		l.push_back(x1); l.push_back(x2);
		l.push_back(x3); l.push_back(x4);
		l.push_back(x5); l.push_back(x6);

		return l;
	}
	std::vector<float> creaListeY(float y1, int mult) {
		std::vector<float> l1;
		float y2, y3, y4, y5, y6;
		y2 = y1 + 0.025f * mult;
		y3 = y2;
		y4 = y1;
		y5 = y4 - 0.025f * mult;
		y6 = y5;

		l1.push_back(y1); l1.push_back(y2);
		l1.push_back(y3); l1.push_back(y4);
		l1.push_back(y5); l1.push_back(y6);

		return l1;
	}
};
