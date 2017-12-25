#include "MyControlEngine.h"
#include "MyGameEngine.h"
#include <string>
#include "MyGraphicEngine.h"

using namespace std;
boolean partieDejaLancee = false;
boolean speedV = false;
boolean lowV = false;
boolean mediumV = false;
float xmouse, ymouse;
float xCoinInfGaucheCaseTouchee;
float yCoinInfGaucheCaseTouchee;
float xCoinSupDroitCaseTouchee;
float yCoinSupDroitCaseTouchee;


int width = 0;
int height = 0;



void MyControlEngine::mjSpeedV(boolean b1) {
	if (b1) { (*vjeu)[0]->setSpeedV(true); speedV = true; }
	else { (*vjeu)[0]->setSpeedV(false); speedV = false; }
}

void MyControlEngine::mjLowV(boolean b2) {
	if (b2) { (*vjeu)[0]->setLowV(true); lowV = true; }
	else { (*vjeu)[0]->setLowV(false); lowV = false; }
}

void MyControlEngine::mjMediumV(boolean b0) {
	if (b0) { (*vjeu)[0]->setMediumV(true); mediumV = true; }
	else { (*vjeu)[0]->setMediumV(false); mediumV = false; }
}

void MyControlEngine::MouseCallback(int button, int state, int x, int y) {
	height = glutGet(GLUT_WINDOW_HEIGHT) / 2;
	width = glutGet(GLUT_WINDOW_WIDTH) / 2;
	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;
	float a = 0.0f;
	xmouse = ((x - width) / (float)width);
	ymouse = ((y - height) / (float)height);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		(*vjeu)[0]->setAfficherMessageFin(false);
		
		//Reinitialisation du boolean "afficherSiPlusDeVaisseauAPoser"
		if ((xmouse < -0.3f) || (xmouse > -0.2f + 0.1f *  (*damier)[0]->getnbC()) || (ymouse < -0.1f) || (ymouse <= 0.1f + 0.2f *  (*damier)[0]->getnbL())) {
			(*vjeu)[0]->setAfficherMessagePlusDeVaisseauxAPoser(false);
		}

		if (((xmouse < 0.07f) || (xmouse > 0.37f)) || ((ymouse > -0.18f)|| (ymouse < -0.77f))) {
			(*vjeu)[0]->setMenuDifficulteDeroule(false);
		}

		r = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
		g = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
		b = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
		a = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));

		//ACHATS DES VAISSEAUX
		/**LOWV**/
		//bouton "-" du vaisseau lowV
		if ((xmouse < -0.38f) && (xmouse > -0.43f) && (ymouse < -0.6f) && (ymouse > -0.65f)) {
			if (((*vjeu)[0]->getnbLAchetes() > 0)&&((*vjeu)[0]->getnbLAchetes() - (*vjeu)[0]->getnbLPoses() != 0)) {
				(*vjeu)[0]->setnbLAchetes((*vjeu)[0]->getnbLAchetes() - 1);
				(*vjeu)[0]->setArgent((*vjeu)[0]->getArgent() + 10);
			}
		}
		//bouton "+" du vaisseau lowV
		else if ((xmouse < -0.31f) && (xmouse > -0.36f) && (ymouse < -0.6f) && (ymouse > -0.65f)) {
			if ((*vjeu)[0]->getArgent() >= 10) {
				(*vjeu)[0]->setnbLAchetes((*vjeu)[0]->getnbLAchetes() + 1);
				(*vjeu)[0]->setArgent((*vjeu)[0]->getArgent() - 10);
			}
		}

		/**MediumV**/
		//boutons "-" du vaisseau mediumV
		if ((xmouse < -0.22f) && (xmouse > -0.27f) && (ymouse < -0.6f) && (ymouse > -0.65f)) {
			if (((*vjeu)[0]->getnbMAchetes() > 0) && ((*vjeu)[0]->getnbMAchetes() - (*vjeu)[0]->getnbMPoses() != 0)) {
				(*vjeu)[0]->setnbMAchetes((*vjeu)[0]->getnbMAchetes() - 1);
				(*vjeu)[0]->setArgent((*vjeu)[0]->getArgent() + 30);
			}
		}
		//bouton "+" du vaisseau mediumV
		else if ((xmouse < -0.15f) && (xmouse > -0.2f) && (ymouse < -0.6f) && (ymouse > -0.65f)) {
			if ((*vjeu)[0]->getArgent() >= 30) {
				(*vjeu)[0]->setnbMAchetes((*vjeu)[0]->getnbMAchetes() + 1);
				(*vjeu)[0]->setArgent((*vjeu)[0]->getArgent() - 30);
			}
		}

		/**SPEEDV**/
		//boutons "-" du vaisseau speedV
		if ((xmouse < -0.05f) && (xmouse > -0.1f) && (ymouse < -0.6f) && (ymouse > -0.65f)) {
			if (((*vjeu)[0]->getnbSAchetes() > 0) && ((*vjeu)[0]->getnbSAchetes() - (*vjeu)[0]->getnbSPoses() != 0)) {
				(*vjeu)[0]->setnbSAchetes((*vjeu)[0]->getnbSAchetes() - 1);
				(*vjeu)[0]->setArgent((*vjeu)[0]->getArgent() + 50);
			}
		}
		//bouton "+" du vaisseau speedV
		else if ((xmouse < 0.02f) && (xmouse > -0.03f) && (ymouse < -0.6f) && (ymouse > -0.65f)) {
			if ((*vjeu)[0]->getArgent() >= 50) {
				(*vjeu)[0]->setnbSAchetes((*vjeu)[0]->getnbSAchetes() + 1);
				(*vjeu)[0]->setArgent((*vjeu)[0]->getArgent() - 50);
			}
		}
		
		//CHOIX DE LA DIFFICULTE
		if ((xmouse > 0.07f) && (xmouse < 0.37f) && (ymouse < -0.67f) && (ymouse > -0.77f)) {
			(*vjeu)[0]->setMenuDifficulteDeroule(!((*vjeu)[0]->getMenuDifficulteDeroule())); 
		}
		for (int i = 0; i < 5; i++) {
			if ((xmouse > 0.07f) && (xmouse < 0.37f) && (ymouse < -0.57f + 0.07f * i) && (ymouse > -0.67f + 0.07f * i) && (*vjeu)[0]->getMenuDifficulteDeroule()) {
				(*vjeu)[0]->reinitializeDifficulte();
				(*vjeu)[0]->setDifficulteChoisie(i, true);
				(*vaisseaux).clear();
				(*vjeu)[0]->setPartieLancee(false);
				(*asteroide).clear();
				//Creation du damier de jeu
				for (int k = 0; k < 10; k++) { (*damier)[0]->setnbL((*vjeu)[0]->getDifficulte() + 1); (*cDamier)[k]->setnbL((*vjeu)[0]->getDifficulte() + 1); }
			}
		}

		//CHOIX DU VAISSEAU "SPEEDV" A POSER
		if ((xmouse >= 0.3f) && (xmouse <= 0.4f) && (ymouse >= -0.3f) && (ymouse <= -0.2f)) {
			if (!speedV){
				mjLowV(false);

				mjSpeedV(true);
				mjMediumV(false);
			}
			else {
				(*vjeu)[0]->setSpeedV(false);  speedV = false;  
			}
		}
		
		//CHOIX DU VAISSEAU "LOWV" A POSER
		else if ((xmouse >= -0.1f) && (xmouse <= 0.0f) && (ymouse >= -0.3f) && (ymouse <= -0.2f)) {
			if (!lowV) {
				mjLowV(true);
				mjSpeedV(false);
				mjMediumV(false);
			}
			else {
				(*vjeu)[0]->setLowV(false); lowV = false;
			}
		}

		//CHOIX DU VAISSEAU "MEDIUM" A POSER
		else if ((xmouse >= 0.1f) && (xmouse <= 0.2f) && (ymouse >= -0.3f) && (ymouse <= -0.2f)) {
			if (!mediumV) {
				mjLowV(false);
				mjSpeedV(false);
				mjMediumV(true);
			}
			else {
				(*vjeu)[0]->setMediumV(false); mediumV = false;
			}
		}

		//QUAND IL L'A CHOISIT, IL LE POSE SUR LE DAMIER
		for (int i = 0; i < (*damier)[0]->getnbC(); i++) {
			for (int j = 0; j < (*damier)[0]->getnbL(); j++) {
				if ((xmouse >= -0.3f + 0.1f * i) && (xmouse <= -0.2f + 0.1f * i) && (ymouse >= -0.1f + 0.2f * j) && (ymouse <= 0.1f + 0.2f * j)) {
					xCoinInfGaucheCaseTouchee = -0.5f + 0.1f * i; xCoinSupDroitCaseTouchee = -0.4f + 0.1f * i; yCoinSupDroitCaseTouchee = 0.1f - 0.2f * j; yCoinInfGaucheCaseTouchee = -0.1f - 0.2f * j;
					//Si la partie n'a pas ete lancee et qu'il n'y a pas de vaisseau sur la case, on peut le poser.
					if ((!(*vjeu)[0]->getPartieLancee()) &&(!(*vjeu)[0]->vaisseauDejaPoseSurLaCase[i][j])) {
						//si le nombre de vaisseau lowV achete est superieur a 0 et qu'on ne les a pas pose, on peut les poser.
						if (((*vjeu)[0]->getnbLAchetes() > 0) && ((*vjeu)[0]->getnbLAchetes() > (*vjeu)[0]->getnbLPoses()) && lowV) {
							vaisseaux->push_back(new LowV(i,j, vaisseaux, missile, asteroide, vjeu, cDamier,vaisseaux->size(), start));
							(*vjeu)[0]->setnbLPoses((*vjeu)[0]->getnbLPoses() + 1);
							(*vjeu)[0]->ligneOccupee[j] = true;
							(*vjeu)[0]->vaisseauDejaPoseSurLaCase[i][j] = true;
						}
						//De meme pour le mediumV
						else if (((*vjeu)[0]->getnbMAchetes() > 0) && ((*vjeu)[0]->getnbMAchetes() > (*vjeu)[0]->getnbMPoses()) && mediumV) {
							vaisseaux->push_back(new MediumV(i, j, vaisseaux, missile, asteroide, vjeu,cDamier,vaisseaux->size(), start));
							(*vjeu)[0]->setnbMPoses((*vjeu)[0]->getnbMPoses() + 1);
							(*vjeu)[0]->ligneOccupee[j] = true;
							(*vjeu)[0]->vaisseauDejaPoseSurLaCase[i][j] = true;
						}
						//De meme pour le speedV
						else if (((*vjeu)[0]->getnbSAchetes() > 0) && ((*vjeu)[0]->getnbSAchetes() > (*vjeu)[0]->getnbSPoses()) && speedV) {
							vaisseaux->push_back(new SpeedV(i, j, vaisseaux, missile, asteroide, vjeu, cDamier, vaisseaux->size(), start));
							(*vjeu)[0]->setnbSPoses((*vjeu)[0]->getnbSPoses() + 1);
							(*vjeu)[0]->ligneOccupee[j] = true;
							(*vjeu)[0]->vaisseauDejaPoseSurLaCase[i][j] = true;
						}
						//Si le joueur veut poser un vaisseau mais qu'il n'en a pas selectionne, le message d'erreur s'affiche
						else if (!lowV && !speedV && !mediumV){
							(*vjeu)[0]->setMessagePlusDeVaisseauxAPoser("Veuillez selectionner un type de vaisseau à poser :)");
							(*vjeu)[0]->setAfficherMessagePlusDeVaisseauxAPoser(true);
						}
						//Si le joueur a selectionne un vaisseau a poser mais qu'il n'en a plus en reserve, le message d'erreur s'affiche
						else if (((*vjeu)[0]->getnbSAchetes() == (*vjeu)[0]->getnbSPoses() && speedV) || ((*vjeu)[0]->getnbLAchetes() == (*vjeu)[0]->getnbLPoses() && lowV) || ((*vjeu)[0]->getnbMAchetes() == (*vjeu)[0]->getnbMPoses()) && mediumV) {
							(*vjeu)[0]->setMessagePlusDeVaisseauxAPoser("Vous n'avez plus de vaisseau de ce type, veuillez en acheter.");
							(*vjeu)[0]->setAfficherMessagePlusDeVaisseauxAPoser(true);
						}
					}
					//Si un vaisseau a deja ete pose sur le case et que le joueur clique dessus, le vaisseau de cette case s'enleve, et peut etre pose a un autre endroit du damier.
					else if (((*vjeu)[0]->vaisseauDejaPoseSurLaCase[i][j])&&(!(*vjeu)[0]->getPartieLancee())) {
						//le vaisseau dont la caseEnDessous est la meme que celle sur laquelle on a clique, est supprime de la liste des vaisseaux poses.
						for (int k = 0; k < (*vaisseaux).size(); k++) {
							if (((*vaisseaux)[k]->xCaseEnDessous == i) && ((*vaisseaux)[k]->yCaseEnDessous == j)) {
								if ((*vaisseaux)[k]->typeVaisseau == "lowV") {
									(*vjeu)[0]->setnbLPoses((*vjeu)[0]->getnbLPoses() - 1);
								}
								else if ((*vaisseaux)[k]->typeVaisseau == "speedV") {

									(*vjeu)[0]->setnbSPoses((*vjeu)[0]->getnbSPoses() - 1);
								}
								else if ((*vaisseaux)[k]->typeVaisseau == "mediumV") {
									(*vjeu)[0]->setnbMPoses((*vjeu)[0]->getnbMPoses() - 1);
								}
								vaisseaux->erase(std::find((*vaisseaux).begin(), (*vaisseaux).end(), (*vaisseaux)[k]));
								(*vjeu)[0]->ligneOccupee[j] = false;
								(*vjeu)[0]->vaisseauDejaPoseSurLaCase[i][j] = false;
							}
						}
					}
				}
			}
		}

		//LANCER LA PARTIE
		if ((xmouse >= 0.45f) && (xmouse <= 0.85f) && (ymouse >= -0.8f) && (ymouse <= -0.6f)) {

			boolean b4 = (*vjeu)[0]->getPartieLancee();

			//Si la partie n'a pas encore été lancée (!partieLancee <=> !b4) 
			if ((!b4)&&(((*vjeu)[0]->getnbLPoses() != 0 ) || ((*vjeu)[0]->getnbSPoses() != 0) || ((*vjeu)[0]->getnbMPoses() != 0)) ) {
				(*vjeu)[0]->setPartieLancee(!b4);
			}
			//Sinon
			else if (b4){
				(*vjeu)[0]->setPartieLancee(!b4);
				(*missile)[0]->setPartieFinie(true);
				for (int i = 0; i < (*asteroide).size(); i++) { (*asteroide).erase(std::find((*asteroide).begin(), (*asteroide).end(), (*asteroide)[i])); }
			}
		}
	}
}