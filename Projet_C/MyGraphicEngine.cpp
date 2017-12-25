#include <string>
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"
#include "SpeedV.h"
#include "LowV.h"
#include "MediumV.h"

using namespace std;
bool b = true;

void MyGraphicEngine::Draw() {
	if (b) {
		missile->push_back(new Missile("", -1.0f, 1.0f, 0, 0, 1, missile, asteroide, vjeu, 0,0.0f,0.0f,0.0f));
		vjeu->push_back(new VariablesDeJeu());
		damier->push_back(new Damier(0, 10, damier, cDamier)); 
	
		b = false;

	}

	//Affichage du nombre de vies des astéroides
	for (int i = 0; i < asteroide->size(); i++) {
		GraphicPrimitives::drawText2D((char*)std::to_string((*asteroide)[i]->getVies() + 1).c_str(), (*asteroide)[i]->getX() + 0.035f, (*asteroide)[i]->getY() - 0.02, 100.0f, 100.0f, 1.0f, 0.6f);
	}

	GraphicPrimitives::drawText2D("Achat de vaisseaux :", -0.9f, 0.7f, 1.0f, 1.0f, 1.0f);
	float a = 0.1f;
	float b = -0.1f;

	for (int i = 0; i < damier->size(); i++) {
		(*damier)[i]->draw();
	}

	(*vjeu)[0]->draw();


	for (int i = 0; i < asteroide->size(); i++) {
	(*asteroide)[i]->draw();
	}

	for (int j = 0; j < vaisseaux->size(); j++) {
	(*vaisseaux)[j]->draw();
	}

	for (int k = 0; k < missile->size(); k++) {
		(*missile)[k]->draw();
	}

}
