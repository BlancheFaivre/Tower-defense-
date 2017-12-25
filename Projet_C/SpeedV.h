#pragma once
#include "Vaisseaux.h"

class SpeedV : public Vaisseaux {
public:
	SpeedV(int xCaseEnDessous, int yCaseEnDessous,std::vector<Vaisseaux*>* v, std::vector<Missile*>* m, std::vector<Asteroide*>* asteroide, std::vector<VariablesDeJeu*>* vjeu, std::vector<CaseDamier*>* cDamier, int id, unsigned long start,
		boolean ex = false, float r=1.0f, float g=0.2f, float b=0.2f, float a = 1.0f) : 
		Vaisseaux("speedV",xCaseEnDessous, yCaseEnDessous,v, m, asteroide, vjeu,cDamier, 5/*frequence*/, 4 /*puissance*/, 12/*vitesse*/, id ,start,ex, r,g,b,a) {
	}


};