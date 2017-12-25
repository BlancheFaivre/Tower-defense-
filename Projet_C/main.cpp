#include <iostream>

#include "Engine.h"
#include "ControlEngineBase.h"
#include "GameEngineBase.h"
#include "GraphicEngineBase.h"
#include "MyControlEngine.h"
#include "MyGameEngine.h"
#include "MyGraphicEngine.h"
#include "CaseDamier.h"
#include "Damier.h"
#include "Vaisseaux.h"
#include "Missile.h"
#include "Asteroide.h"
#include "VariablesDeJeu.h"

int main(int argc, char* argv[]) {
	unsigned long startTime_;
	startTime_ = GetTickCount();
	Engine e(argc, argv);

	std::vector<Vaisseaux*> vaisseaux;
	std::vector<Damier*> damier;
	std::vector<CaseDamier*> cDamier;
	std::vector<Missile*> missile;
	std::vector<Asteroide*> asteroide;
	std::vector<VariablesDeJeu*> vjeu;

	GraphicEngineBase* ge = new MyGraphicEngine(&vaisseaux, &damier,&cDamier,&missile, startTime_, &asteroide, &vjeu);
	GameEngineBase* gme = new MyGameEngine(&vaisseaux, &damier, &cDamier,&missile, startTime_, &asteroide, &vjeu);
	ControlEngineBase* ce = new MyControlEngine(&vaisseaux, &damier,&cDamier,&missile, startTime_, &asteroide,&vjeu);

	e.setGraphicEngine(ge);
	e.setGameEngine(gme);
	e.setControlEngine(ce);



	e.start();
	return 0;
}
