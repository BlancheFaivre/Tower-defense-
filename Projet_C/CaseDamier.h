#pragma once
#include "GraphicPrimitives.h"

class CaseDamier {
private:
	std::vector<CaseDamier*>* vCaseDamier;
	float cpt2;
	int nbLignes;
public:
	CaseDamier(std::vector<CaseDamier*>* damier, int nbLignes) : vCaseDamier(damier), nbLignes(nbLignes) {
		cpt2 = 0.1f * (vCaseDamier->size() % 10);
	}

	void draw();

	//getter et setter du nombre de lignes
	int getnbL() {
		return nbLignes;
	}
	void setnbL(int n) {
		nbLignes = n;
	}

};
