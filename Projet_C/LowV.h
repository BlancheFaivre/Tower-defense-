#pragma once
#include "Vaisseaux.h"

class LowV : public Vaisseaux {
public:
	LowV(int xCaseEnDessous,int yCaseEnDessous, std::vector<Vaisseaux*>* v, std::vector<Missile*>* m, std::vector<Asteroide*>* asteroide, std::vector<VariablesDeJeu*>* vjeu, std::vector<CaseDamier*>* cDamier, int id, unsigned long start,
		boolean ex = false, float r = 0.0f, float g = 1.0f, float b = 0.0f, float a = 1.0f) :
		Vaisseaux("lowV", xCaseEnDessous, yCaseEnDessous, v, m, asteroide, vjeu,cDamier, 5/*frequence*/, 1 /*puissance*/, 8/*vitesse*/, id, start, ex, r, g, b, a) {
	}


};


