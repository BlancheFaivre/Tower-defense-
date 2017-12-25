#pragma once
#include "GraphicPrimitives.h"
#include "CaseDamier.h"

class Damier {
private :
	int nbLignes;
	int nbColonnes;
	std::vector<Damier*>* vDamier;
	std::vector<CaseDamier*>* vCaseDamier;
public:
	Damier(int nbLignes, int nbColonnes, std::vector<Damier*>* damier, std::vector<CaseDamier*>* cd) : nbLignes(nbLignes), nbColonnes(nbColonnes), vDamier(damier), vCaseDamier(cd){
		for (int i = 0; i < nbColonnes; i++) {
			vCaseDamier->push_back(new CaseDamier(vCaseDamier, nbLignes));
		}
	}

	//getter et setter du nombre de colonnes
	int getnbC() {
		return nbColonnes;
	}
	void setnbC(int n) {
		nbColonnes = n;
	}
	//getter et setter du nombre de lignes
	int getnbL() {
		return nbLignes;
	}
	void setnbL(int n) {
		nbLignes = n;
	}
	
	void draw();

};
