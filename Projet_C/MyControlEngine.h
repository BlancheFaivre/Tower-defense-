#pragma once
#include "myEngine.h"

class MyControlEngine : public ControlEngineBase, myEngine {
public:
	MyControlEngine(std::vector<Vaisseaux*>* vaisseaux_, std::vector<Damier*>* damier_,
		std::vector<CaseDamier*>* cDamier_, std::vector<Missile*>* missile_, unsigned long start, std::vector<Asteroide*>* asteroide, std::vector<VariablesDeJeu*>* vjeu) : 
		myEngine(vaisseaux_, damier_, cDamier_, missile_, start, asteroide, vjeu){}

	//fonctions de mise a jour lors du choix des vaisseaux a poser par le joueur
	void mjMediumV(boolean b0);
	void mjSpeedV(boolean b1);
	void mjLowV(boolean b2);
	virtual void MouseCallback(int button, int state, int x, int y);
};
