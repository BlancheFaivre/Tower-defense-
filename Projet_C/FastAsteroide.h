#pragma once
#include "Asteroide.h"

class FastAsteroide : public Asteroide {
public:
	FastAsteroide(int nbLignes, unsigned long start, std::vector<Asteroide*>* asteroide, int id, float r = 1.0f, float g = 1.0f, float b = 0.5f, float a = 0.5f) :
		Asteroide("fast",nbLignes, 9, 3, start, asteroide, id, r,g,b,a) {}


};
