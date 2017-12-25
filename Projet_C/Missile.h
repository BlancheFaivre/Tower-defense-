#pragma once
#include "GraphicPrimitives.h"
#include "ObjetsAandM.h"
#include "Asteroide.h"
#include "VariablesDeJeu.h"

class Missile : public ObjetsAandM {
private :
	int puissance;
	boolean partieFinie = false;
	std::string typeVaisseau;
	std::vector<Asteroide*>* asteroide;
	std::vector<Missile*>* missile;
	std::vector<VariablesDeJeu*>* vjeu;
	std::vector<CaseDamier*>* cDamier;
public :
	Missile(std::string typeVaisseau,float fx1, float fy1, int puissance, int vitesse, unsigned long start, std::vector<Missile*>*missile,std::vector<Asteroide*>* asteroide,
		std::vector<VariablesDeJeu*>* vjeu, std::vector<CaseDamier*>* cDamier, int id,float r = 0.5f, float g = 0.5f, float b = 0.5f, float a = 0.5f) : 
		//appel du constructeur de la classe mere ObjetsAandM
		ObjetsAandM(fx1, fy1,vitesse, start, id,1 /*mult qui est égal à 2 seulement pour les astéroides qui sont 2fois plus gros que les missiles*/, r,g,b,a), 
		//affectation des valeur aux variables
		puissance(puissance), missile(missile), asteroide(asteroide) , typeVaisseau(typeVaisseau), vjeu(vjeu), cDamier(cDamier){}
	
	
	void tick();
	void draw();
	boolean getPartieFinie() {
		return partieFinie;
	}
	void setAste(std::vector<Asteroide*>* a) {
		asteroide = a;
	}
	void setPartieFinie(boolean b) {
		partieFinie = b;
		(*asteroide).clear();
	}
};
