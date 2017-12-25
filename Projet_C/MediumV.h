#pragma once
#include "Vaisseaux.h"

class MediumV : public Vaisseaux {
public:
	MediumV(int xCaseEnDessous, int yCaseEnDessous, std::vector<Vaisseaux*>* v, std::vector<Missile*>* m, std::vector<Asteroide*>* asteroide, std::vector<VariablesDeJeu*>* vjeu, std::vector<CaseDamier*>* cDamier, int id, unsigned long start,
		boolean ex = false, float r = 0.0f, float g = 0.0f, float b = 1.0f, float a = 1.0f) :
		Vaisseaux("mediumV", xCaseEnDessous, yCaseEnDessous, v, m, asteroide,vjeu,cDamier, 5/*frequence*/, 2 /*puissance*/, 10/*vitesse*/, id, start, ex, r, g, b, a) {
	}

};


