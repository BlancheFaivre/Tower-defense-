#pragma once
#include "Asteroide.h"

class StrongAsteroide : public Asteroide {
public:
	StrongAsteroide(int nbLignes, unsigned long start, std::vector<Asteroide*>* asteroide, int id, float r = 0.1f, float g = 0.1f, float b = 0.9f, float a = 0.5f) :
		Asteroide("strong",nbLignes, 14, 2, start, asteroide, id,r,g,b,a) {}


};
