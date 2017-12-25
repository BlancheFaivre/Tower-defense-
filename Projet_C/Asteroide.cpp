#include "Asteroide.h"
int nbTicksA = 0;

void Asteroide::draw() {
	if (type == "fast") {
		if (nbTicksA % 200 == 0) GraphicPrimitives::drawFillPolygone2D(listeX, listeY, 1.0f, 0.0f, 0.5f, a);
		else GraphicPrimitives::drawFillPolygone2D(listeX, listeY, r, g, b, a);
	}
	else if (type == "strong") {
		if (vies >= 9) GraphicPrimitives::drawFillPolygone2D(listeX, listeY, r, g, b, a);
		else if (vies >= 4) GraphicPrimitives::drawFillPolygone2D(listeX, listeY, 0.5, 0.5, 0.5, 0.6);
		else GraphicPrimitives::drawFillPolygone2D(listeX, listeY, 0.2, 0.2, 0.2, 1.0);
	}
	else GraphicPrimitives::drawFillPolygone2D(listeX, listeY, r, g, b, a);
}

void Asteroide::tick() {
	nbTicksA++;
	//Si l'asteroide n'a pas touche de vaisseau il avance
	if (!aToucheUnVaisseau) {
		//S'il n'est pas arrive a la fin du damier il avance
		if (listeX[0] > -0.3f){
			for (int i = 0; i < listeX.size(); i++) {
				listeX[i] -= 0.00007f * vitesse;
			}
		}
		//Sinon on le supprime
		else {
			(*asteroide).erase(std::find((*asteroide).begin(), (*asteroide).end(), this));
		}
	}
	//Il a touche un vaisseau
	else {
		(*asteroide).erase(std::find((*asteroide).begin(), (*asteroide).end(), this));
	}
	
}