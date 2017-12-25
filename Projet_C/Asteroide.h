#pragma once
#include "GraphicPrimitives.h"
#include "ObjetsAandM.h"
#include <string>

class Asteroide : public ObjetsAandM {
private:
	int vies;
	int vitesse;
	std::string stringVie = std::to_string(vies);
	std::vector<Asteroide*>* asteroide;
	boolean aToucheUnVaisseau = false;
	std::string type;
public:
	Asteroide(std::string type, int nbLignes, int vies, int vitesse, unsigned long start, std::vector<Asteroide*>* asteroide, int id, float r = 0.5f, float g = 0.5f, float b = 0.5f, float a = 0.5f) :
		ObjetsAandM(-0.5f + 0.1 * 11, 0.0f - 0.2f *(rand() % static_cast<int>(nbLignes)), vitesse, start, id, 2, r, g, b, a),type(type), vies(vies),vitesse(vitesse), asteroide(asteroide){}


	int getVies() {
		return vies;
	}
	void decrementeVies() {
		vies -= 1;
		stringVie = std::to_string(vies);
	}
	void tick();
	void draw();
};
