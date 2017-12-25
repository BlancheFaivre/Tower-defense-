#include "Missile.h"
unsigned int diffInMilliSeconds;
int cpt = 0;
std::string s;
std::string s1;
boolean dejaAffiche = false;
boolean dejaP = false;
boolean dejaEfface = false;

void Missile::draw() {
	GraphicPrimitives::drawFillPolygone2D(listeX, listeY, r, g, b, a);
}

void Missile::tick() {
	s1 = "";
	dejaAffiche = false;
	dejaEfface = false;
	// Le missile avance vers l'astéroïde
	if ((*missile)[0] != this) { for (int i = 0; i < listeX.size(); i++) { listeX[i] += 0.0025f * vitesse; } }

	//S'il y'a des astéroïdes sur le jeu
	if ((*asteroide).size() != 0) {
		for (int j = 0; j < asteroide->size(); j++) {
			//Si l'astéroïde est sur la même ligne que le missile
			if ((*asteroide)[j]->listeY[0] == listeY[0]) {
				//Si le devant du missile a touché l'astéroïde
				if (listeX[0] >= (*asteroide)[j]->listeX[0]) {
					//Le missile est effacé de la liste des missiles
					if (!dejaEfface) { (*missile).erase(std::find((*missile).begin(), (*missile).end(), this)); dejaEfface = true; }
					//Si le missile a plus de 0 vies il ne disparait pas mais perd un certains nombre de vies en fonction du type de vaisseau
					if ((*asteroide)[j]->getVies() > 0) {
						if (typeVaisseau == "lowV") cpt = 1;
						else if (typeVaisseau == "mediumV") cpt = 2;
						else if (typeVaisseau == "speedV") cpt = 3;
						for (int k = 0; k < cpt; k++) { if ((*asteroide)[j]->getVies() > 0) (*asteroide)[j]->decrementeVies(); }
					}
					//Si il ne lui restait plus qu'une vie, l'astéroïde est effacé de la liste des astéroïdes 
					else {
						(*vjeu)[0]->score += 10;
						(*asteroide).erase(std::find((*asteroide).begin(), (*asteroide).end(), (*asteroide)[j]));
						if (((*asteroide).size() == 0)&&(((*vjeu)[0]->nbLowAsteroidesCrees + (*vjeu)[0]->nbStrongAsteroidesCrees + (*vjeu)[0]->nbFastAsteroidesCrees) == (*vjeu)[0]->nbAsteroidesACreer)) {
							(*missile)[0]->setPartieFinie(true);
							(*vjeu)[0]->setPartieLancee(false);

							//Ici, mettre l'argent qui augmente en fonction de la diff (switch)
							int diff = (*vjeu)[0]->getDifficulte();
							int ar = (*vjeu)[0]->getArgent();
							switch (diff) {
							case 0:
								(*vjeu)[0]->setArgent(ar + 10);
								s = "Bravo, vous avez gagne 10 pieces !";
								break;
							case 1:
								(*vjeu)[0]->setArgent(ar + 15);
								s = "Bravo, vous avez gagne 15 pieces !";
								break;
							case 2:
								(*vjeu)[0]->setArgent(ar + 20);
								s = "Bravo, vous avez gagne 20 pieces !";
								break;
							case 3:
								(*vjeu)[0]->setArgent(ar + 25);
								s = "Bravo, vous avez gagne 25 pieces !";
								break;
							case 4:
								(*vjeu)[0]->setArgent(ar + 30);
								s = "Bravo, vous avez gagne 30 pieces !";
								break;
							}
							//si le score est plus eleve que le meilleur score, le meilleur score change
							if ((*vjeu)[0]->score > (*vjeu)[0]->meilleurScore) (*vjeu)[0]->meilleurScore = (*vjeu)[0]->score;
							//le nombre de pieces gagnees s'affiche a la fin de la partie
							(*vjeu)[0]->setMessageFin(s);
							(*vjeu)[0]->setAfficherMessageFin(true);
						}
					}
				}
			}
		}
		//Si le missile arrive au bout du damier il est efface
		if (listeX[listeX.size() - 2] >= 0.7f) {
			diffInMilliSeconds = GetTickCount() - start;
			if (this != (*missile)[0]) (*missile).erase(std::find((*missile).begin(), (*missile).end(), this));
		}
	}
	else {
		//Si le missile arrive au bout du damier il est efface
		if (listeX[listeX.size() - 2] >= 0.7f) {
			diffInMilliSeconds = GetTickCount() - start;
			(*missile).erase(std::find((*missile).begin(), (*missile).end(), this));
		}
	}

}
