#pragma once
#include "GraphicPrimitives.h"
#include "Missile.h"
#include "CaseDamier.h"
#include "VariablesDeJeu.h"
#include "LowAsteroide.h"
#include "StrongAsteroide.h"
#include "FastAsteroide.h"

class Vaisseaux {
private :
	float x1, y1, x2, y2, x3, y3;
	std::vector<CaseDamier*>* cDamier;
public:
	Vaisseaux(std::string vaisseau, int xCaseEnDessous, int yCaseEnDessous,std::vector<Vaisseaux*>* v, std::vector<Missile*>* m, std::vector<Asteroide*>* asteroide, std::vector<VariablesDeJeu*>* vjeu, std::vector<CaseDamier*>* cDamier, int freq, int puiss, int vit, int id, unsigned long start, boolean ex = false, float r = 0.5f, float g = 0.5f, float b = 0.5f, float a = 0.5f)
		:xCaseEnDessous(xCaseEnDessous), yCaseEnDessous(yCaseEnDessous), x1(-0.3f + 0.1f * xCaseEnDessous), y1(-0.05f - 0.2f * yCaseEnDessous), r(r), g(g), b(b), a(a), frequence(freq), listeVaisseaux(v),puissance(puiss), vitesse (vit), listeMissiles(m), start(start),typeVaisseau(vaisseau), listeAsteroides(asteroide), vjeu(vjeu), id(id), cDamier(cDamier){
		x2 = x1 + 0.1f;
		y2 = y1 + 0.05f;
		y3 = y3 = y1 + 0.1f;
		x3 = x1;
	}

	int xCaseEnDessous;
	int yCaseEnDessous;

	//frequence 
	int frequence;

	//puissance et vitesse
	int puissance;
	int vitesse;

	//id
	int id;


	//boolean si la partie est commencée
	bool lancerPartie;

	//liste des missiles
	std::vector<Missile*>* listeMissiles;
	std::vector<Asteroide*>* listeAsteroides;
	std::vector<Vaisseaux*>* listeVaisseaux;
	std::vector<VariablesDeJeu*>* vjeu;

	//startTime
	unsigned long start;

	//string vaisseau choisi
	std::string typeVaisseau;


	/*void resetLignes() {

	}*/

	// color
	float r;
	float g;
	float b;
	float a;

	float getX2() {
		return x2;
	}
	float getY2() {
		return y2;
	}


	void newMissile();
	void draw();
	void tick();

};
