#pragma once
#include "Engine.h"
#include "Vaisseaux.h"
#include "CaseDamier.h"
#include "Damier.h"
#include "Missile.h"
#include "Asteroide.h"
#include "VariablesDeJeu.h"
#include "SpeedV.h"
#include "LowV.h"
#include "MediumV.h"

class myEngine {
protected :
	std::vector<Vaisseaux*>* vaisseaux;
	std::vector<Damier*>* damier;
	std::vector<CaseDamier*>* cDamier;
	std::vector<Missile*>* missile;
	std::vector<Asteroide*>* asteroide;
	std::vector<VariablesDeJeu*>* vjeu;
	unsigned long start;
public  : 
	myEngine(std::vector<Vaisseaux*>* vaisseaux_, std::vector<Damier*>* damier_,
		std::vector<CaseDamier*>* cDamier_, std::vector<Missile*>* missile_, unsigned long start, std::vector<Asteroide*>* asteroide, std::vector<VariablesDeJeu*>* vjeu) : vaisseaux(vaisseaux_), damier(damier_), cDamier(cDamier_), missile(missile_), start(start), asteroide(asteroide), vjeu(vjeu) {}
};