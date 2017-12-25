#pragma once
#include "myEngine.h"
#include "GraphicPrimitives.h"
#include <stdio.h>

class MyGraphicEngine : public GraphicEngineBase, myEngine {
public:

	MyGraphicEngine(std::vector<Vaisseaux*>* vaisseaux_, std::vector<Damier*>* damier_,
		std::vector<CaseDamier*>* cDamier_, std::vector<Missile*>* missile_, unsigned long start, std::vector<Asteroide*>* asteroide, std::vector<VariablesDeJeu*>* vjeu) :
		myEngine(vaisseaux_, damier_,cDamier_,missile_, start, asteroide, vjeu){}

	virtual void Draw();

};
