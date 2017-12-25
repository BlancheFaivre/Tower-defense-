#pragma once

#include "myEngine.h"
#include "GameEngineBase.h"

class MyGameEngine : public GameEngineBase, myEngine {
public:
	MyGameEngine(std::vector<Vaisseaux*>* vaisseaux, std::vector<Damier*>* damier,
		std::vector<CaseDamier*>* cDamier, std::vector<Missile*>* missile_, unsigned long start, std::vector<Asteroide*>* asteroide, std::vector<VariablesDeJeu*>* vjeu)
		: myEngine(vaisseaux, damier, cDamier, missile_, start, asteroide, vjeu){
	}
	virtual void idle();
};