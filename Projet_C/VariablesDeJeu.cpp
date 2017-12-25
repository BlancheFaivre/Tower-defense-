#include "VariablesDeJeu.h"


//ATTNETION : IL FAUT 3 SORTES D4ASTEROIDES


void VariablesDeJeu::reinitializeTabs() {
	for (int j = 0; j < 20; j++) {
		for (int i = 0; i < 20; i++) {
			vaisseauDejaPoseSurLaCase[i][j] = false;
		}
		ligneOccupee[j] = false;
	}
}

void VariablesDeJeu::reinitializeDifficulte() {
	for (int i = 0; i < 5; i++) {
		difficulteChoisie[i] = false;
		difficulte = 0;
	}
}


void VariablesDeJeu::dessinTriangle(float x1, float y1, float r, float g, float b, float a = 1.0f){
	float x2 = x1 + 0.1f;
	float y2 = y1 + 0.05f;
	float y3 = y3 = y1 + 0.1f;
	float x3 = x1;
	GraphicPrimitives::drawFillTriangle2D(x1, y1, x2, y2, x3, y3, r, g, b, a);
}

void VariablesDeJeu::ticks() {

}

void VariablesDeJeu::draw() {
	//Choix des difficultés
	GraphicPrimitives::drawOutlinedRect2D(0.07f, 0.67f, 0.3f, 0.1f, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("Difficulte", 0.125f, 0.7f, 1.0f, 1.0f, 1.0f, 1.0f);
	if (menuDifficulteDeroule) {
		for (int i = 0; i < 5; i++) {
			GraphicPrimitives::drawOutlinedRect2D(0.07f, 0.60f - 0.07f* i, 0.3f, 0.07f, 1.0f, 1.0f, 1.0f, 1.0f);
			GraphicPrimitives::drawText2D((char*)std::to_string(i).c_str(), 0.2f, 0.617f - 0.07f*i, 1.0f, 1.0f, 1.0f, 1.0f);
			if (difficulteChoisie[i]) {
				difficulte = i;
				GraphicPrimitives::drawFillRect2D(0.07f, 0.60f - 0.07f* i, 0.3f, 0.07f, 1.0f, 1.0f, 1.0f, 1.0f);
				GraphicPrimitives::drawText2D((char*)std::to_string(i).c_str(), 0.2f, 0.617f - 0.07f*i, 0.0f, 0.0f, 0.0f, 1.0f);
			}
		}
	}

	//Affichage du score
	GraphicPrimitives::drawText2D("Meilleur score : ", -0.9f, 0.55f, 0.5f, 0.5f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D((char*)std::to_string(meilleurScore).c_str(), -0.58f, 0.55f, 0.5f, 0.5f, 1.0f, 1.0f);


	GraphicPrimitives::drawText2D("SCORE : ", -0.84f, 0.45f, 0.5f, 0.5f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D((char*)std::to_string(score).c_str(), -0.64f, 0.45f, 0.5f, 0.5f, 1.0f, 1.0f);


	//Choix des vaisseaux et du bouton partieLancee
	if (!partieLancee) {
		GraphicPrimitives::drawFillRect2D(0.45f, 0.6f, 0.4f, 0.2f, 1.0f, 0.6f, 0.2f, 1.0f);
		GraphicPrimitives::drawText2D((char*)partie.c_str(), 0.5f, 0.68f, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	else {
		GraphicPrimitives::drawFillRect2D(0.45f, 0.6f, 0.4f, 0.2f, 1.0f, 0.6f, 0.2f, 0.4f);
		GraphicPrimitives::drawText2D((char*)partie.c_str(), 0.61f, 0.68f, 1.0f, 1.0f, 1.0f, 1.0f);
	}

	/*LOWV A ACHETER*/
	float r0 = 0.0f, g0 = 1.0f, b0 = 0.0f, a0 = 1.0f;
	dessinTriangle(-0.4f, 0.67f, r0, g0, b0, a0);
	//plus et moins pour le low
	GraphicPrimitives::drawOutlinedRect2D(-0.43f, 0.6f, 0.05f, 0.05f, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawOutlinedRect2D(-0.36f, 0.6f, 0.05f, 0.05f, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("-", -0.42f, 0.61f, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("+", -0.35f, 0.61f, 1.0f, 1.0f, 1.0f, 1.0f);


	/**MEDIUM A ACHETER**/
	float r1 = 0.0f, g1 = 0.0f, b1 = 1.0f, a1 = 1.0f;
	dessinTriangle(-0.25f, 0.67f, r1, g1, b1, a1);
	//plus et moins pour le medium
	GraphicPrimitives::drawOutlinedRect2D(-0.27f, 0.6f, 0.05f, 0.05f, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawOutlinedRect2D(-0.2f, 0.6f, 0.05f, 0.05f, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("-", -0.26f, 0.61f, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("+", -0.19f, 0.61f, 1.0f, 1.0f, 1.0f, 1.0f);

	/**SPEED A ACHETER**/
	float r2 = 1.0f, g2 = 0.2f, b2 = 0.2f, a2 = 1.0f;
	dessinTriangle(-0.1f, 0.67f, r2, g2, b2, a2);
	//plus et moins pour le speedV
	GraphicPrimitives::drawOutlinedRect2D(-0.1f, 0.6f, 0.05f, 0.05f, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawOutlinedRect2D(-0.03f, 0.6f, 0.05f, 0.05f, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("-", -0.09f, 0.61f, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("+", -0.02f, 0.61f, 1.0f, 1.0f, 1.0f, 1.0f);

	/**VAISSEAUX A CHOISIR DE POSER**/
	if ((!afficherMessagePlusDeVaisseauxAPoser) && (!afficherMessageFin)) {
		/**LOWV**/
		if (!lowV) {
			float r = 0.0f, g = 1.0f, b = 0.0f, a = 1.0f;
			dessinTriangle(-0.1f, 0.2f, r, g, b, a);
		}
		else {
			dessinTriangle(-0.1f, 0.2f, 0.9f, 1.0f, 0.9f);
		}


		/**MEDIUM**/
		if (!mediumV) {
			float r = 0.0f, g = 0.0f, b = 1.0f, a = 1.0f;
			dessinTriangle(0.1f, 0.2f, r, g, b, a);
		}
		else {
			dessinTriangle(0.1f, 0.2f, 0.9f, 1.0f, 0.9f);
		}


		/**SPEEDV**/
		if (!speedV) {
			float r = 1.0f, g = 0.2f, b = 0.2f, a = 1.0f;
			dessinTriangle(0.3f, 0.2f, r, g, b, a);
		}
		else {
			dessinTriangle(0.3f, 0.2f, 1.0f, 0.9f, 0.9f);
		}


		/**Affichage du nombre de vaisseaux posés**/
		GraphicPrimitives::drawText2D("Achetez des vaisseaux, choisissez une difficulte", -0.35f, 0.46f, 0.9f, 1.0f, 1.0f, 0.6f);
		GraphicPrimitives::drawText2D("puis selectionnez les vaisseaux que vous voulez poser :", -0.35f, 0.40f, 0.9f, 1.0f, 1.0f, 0.6f);
		//lowV
		GraphicPrimitives::drawText2D((char*)std::to_string(nbLowVAchetes - nbLowVPoses).c_str(), -0.1f, 0.32f, 0.9f, 1.0f, 1.0f, 1.0f);
		//MediumV
		GraphicPrimitives::drawText2D((char*)std::to_string(nbMediumVAchetes - nbMediumVPoses).c_str(), 0.1f, 0.32f, 0.9f, 1.0f, 1.0f, 1.0f);
		//SpeedV
		GraphicPrimitives::drawText2D((char*)std::to_string(nbSpeedVAchetes - nbSpeedVPoses).c_str(), 0.3f, 0.32f, 0.9f, 1.0f, 1.0f, 1.0f);
	}



	/**Affichage des vaisseaux achetés**/
	//lowV
	GraphicPrimitives::drawText2D((char*)std::to_string(nbLowVAchetes).c_str(), -0.4f, 0.785f, 0.9f, 1.0f, 1.0f, 0.9f);
	//MediumV
	GraphicPrimitives::drawText2D((char*)std::to_string(nbMediumVAchetes).c_str(), -0.24f, 0.785f, 0.9f, 1.0f, 1.0f, 0.9f);
	//SpeedV
	GraphicPrimitives::drawText2D((char*)std::to_string(nbSpeedVAchetes).c_str(), -0.09f, 0.785f, 0.9f, 1.0f, 1.0f, 0.9f);



	/**Affichage de l'argent du joueur**/
	GraphicPrimitives::drawOutlinedRect2D(-0.904f, -0.606f, 0.407f, 1.01f, 0.7f, 0.8f, 0.8f, 1.0f);
	GraphicPrimitives::drawFillRect2D(-0.9f, -0.6f, 0.4f, 1.0f, 0.9f,1.0f,1.0f,0.9f);
	GraphicPrimitives::drawText2D("Argent : ", -0.87f, 0.3f, 0.1f, 0.2f, 0.2f, 1.0f);
	GraphicPrimitives::drawText2D((char*)std::to_string(argent).c_str(), -0.68f, 0.3f, 0.1f, 0.2f, 0.2f, 1.0f);
	GraphicPrimitives::drawFillPolygone2D(listexa, listeya, 1.0f, 1.0f, 0.0f, 1.0f);

	/**Affichage du prix des vaisseaux**/
	//lowV
	float rl = 0.0f, gl = 1.0f, bl = 0.0f, al = 1.0f;
	dessinTriangle(-0.87f, 0.0f, rl, gl, bl, al);
	GraphicPrimitives::drawText2D("10", -0.65f, 0.03f, -0.4f, 0.2f, 0.2f, 1.0f);
	GraphicPrimitives::drawFillPolygone2D(listeXl, listeYl, 1.0f, 1.0f, 0.0f, 1.0f);

	//MediumV
	float rm = 0.0f, gm = 0.0f, bm = 1.0f, am = 1.0f;
	dessinTriangle(-0.87f, -0.2f, rm, gm, bm, am);
	GraphicPrimitives::drawText2D("30", -0.65f, -0.17f, 0.1f, 0.2f, 0.2f, 1.0f);
	GraphicPrimitives::drawFillPolygone2D(listeXM, listeYM, 1.0f, 1.0f, 0.0f, 1.0f);

	//SpeedV
	float rs = 1.0f, gs = 0.2f, bs = 0.2f, as = 1.0f;
	dessinTriangle(-0.87f, -0.4f, rs, gs, bs, as);
	GraphicPrimitives::drawText2D("50", -0.65f, -0.37f, 0.1f, 0.2f, 0.2f, 1.0f);
	GraphicPrimitives::drawFillPolygone2D(listeXS, listeYS, 1.0f, 1.0f, 0.0f, 1.0f);



	//Affichage message de fin
	if (afficherMessageFin) {
		GraphicPrimitives::drawText2D((char*)getMessageFin().c_str(), -0.23f, 0.33f, 1.0f, 1.0f, 1.0f);
		/*if (getDiffAChange() != "") {
			GraphicPrimitives::drawText2D("Attention, essayez de gagner d'autres vaisseaux avant de changer de difficulte :", -0.23f, 0.23f, 1.0f, 1.0f, 1.0f);
			GraphicPrimitives::drawText2D("les autres niveaux sont plus compliques !", -0.23f, 0.17f, 1.0f, 1.0f, 1.0f);
		}*/
		GraphicPrimitives::drawFillPolygone2D(listexf, listeyf, 1.0f, 1.0f, 0.0f, 1.0f);
	}

	//Affichage message "plus de vaisseaux à poser
	if ((afficherMessagePlusDeVaisseauxAPoser)&&(!afficherMessageFin)) {
		GraphicPrimitives::drawText2D((char*)messagePlusDeVaisseauxAPoser.c_str(), -0.35f, 0.3f, 1.0f, 1.0f, 1.0f);
	}

}