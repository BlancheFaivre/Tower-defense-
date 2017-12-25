#pragma once
#include "Asteroide.h"

class LowAsteroide : public Asteroide {
public:
	LowAsteroide(int nbLignes, unsigned long start, std::vector<Asteroide*>* asteroide, int id, float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 0.5f) :
		Asteroide("low",nbLignes, 9, 2, start, asteroide, id, r,g,b,a) {}


};
