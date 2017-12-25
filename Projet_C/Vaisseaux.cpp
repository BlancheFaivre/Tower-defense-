#include "Vaisseaux.h"
boolean boo = true;
int nbTicks = 0;
boolean bo = true;
int myI;
int nbm;

void Vaisseaux::draw() {
	GraphicPrimitives::drawFillTriangle2D(x1, y1, x2, y2, x3, y3, r, g, b, a);
}

void Vaisseaux::newMissile() {
	listeMissiles->push_back(new Missile(typeVaisseau, x1 + 0.1f, y1 + 0.05f, puissance, vitesse, start,listeMissiles, listeAsteroides, vjeu, cDamier, listeMissiles->size(), r, g, b, a));
}

void Vaisseaux::tick() {
	//Creation des asteroïdes
	if ((*vjeu)[0]->getCreationAste()) {
		switch ((*vjeu)[0]->getnbLPoses() + (*vjeu)[0]->getnbSPoses() + (*vjeu)[0]->getnbMPoses()){
		case 0: nbm = 0; break;
		case 1: nbm = 0; break;
		case 2: nbm = 0; break;
		case 3: nbm = 0; break;
		case 4: nbm = 1000; break;
		case 5: nbm = 1000; break;
		case 6: nbm = 2000; break;
		case 7: nbm = 2000; break;
		case 8: nbm = 3000; break;
		case 9: nbm = 3000; break;
		case 10: nbm = 4000; break;
		case 11: nbm = 4000; break;
		case 12: nbm = 5000; break;
		case 13: nbm = 6000; break;
		case 14: nbm = 6000; break;
		}
		switch ((*vjeu)[0]->getDifficulte()) {
		case 0:
			if ((nbTicks % (nbm + 3264) == 0) && ((*vjeu)[0]->nbLowAsteroidesCrees < 3)) { listeAsteroides->push_back(new LowAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbLowAsteroidesCrees++; }
			(*vjeu)[0]->nbAsteroidesACreer = 3;
			break;
		case 1: 
			if ((nbTicks % (nbm + 5064) == 0) && ((*vjeu)[0]->nbLowAsteroidesCrees < 2)) { listeAsteroides->push_back(new LowAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbLowAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 5064) == 0) &&((*vjeu)[0]->nbStrongAsteroidesCrees < 1)){listeAsteroides->push_back(new StrongAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbStrongAsteroidesCrees++;}
			else if ((nbTicks % (nbm + 5064) == 0) && ((*vjeu)[0]->nbLowAsteroidesCrees < 3)) { listeAsteroides->push_back(new LowAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbLowAsteroidesCrees++; }
			(*vjeu)[0]->nbAsteroidesACreer = 4;
			break;

		case 2:
			if ((nbTicks % (nbm + 5064) == 0) && ((*vjeu)[0]->nbLowAsteroidesCrees < 1)) { listeAsteroides->push_back(new LowAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbLowAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 5064) == 0) &&((*vjeu)[0]->nbStrongAsteroidesCrees < 1)){listeAsteroides->push_back(new StrongAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbStrongAsteroidesCrees++;}
			else if ((nbTicks % (nbm + 5064) == 0) && ((*vjeu)[0]->nbFastAsteroidesCrees < 1)) { listeAsteroides->push_back(new FastAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbFastAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 5064) == 0) && ((*vjeu)[0]->nbLowAsteroidesCrees < 2)) { listeAsteroides->push_back(new LowAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbLowAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 5064) == 0) && ((*vjeu)[0]->nbStrongAsteroidesCrees < 2)) { listeAsteroides->push_back(new StrongAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbStrongAsteroidesCrees++; }
			(*vjeu)[0]->nbAsteroidesACreer = 5;
			break;
		case 3 :
			if ((nbTicks % (nbm + 5064) == 0) && ((*vjeu)[0]->nbLowAsteroidesCrees < 2)) { listeAsteroides->push_back(new LowAsteroide((*cDamier)[0]->getnbL(),1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbLowAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 5064) == 0) && ((*vjeu)[0]->nbStrongAsteroidesCrees < 1)) { listeAsteroides->push_back(new StrongAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbStrongAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 5064) == 0) && ((*vjeu)[0]->nbFastAsteroidesCrees < 1)) { listeAsteroides->push_back(new FastAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbFastAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 5064) == 0) && ((*vjeu)[0]->nbLowAsteroidesCrees < 3)) { listeAsteroides->push_back(new LowAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbLowAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 5064) == 0) && ((*vjeu)[0]->nbFastAsteroidesCrees < 2)) { listeAsteroides->push_back(new FastAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbFastAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 5064) == 0) && ((*vjeu)[0]->nbStrongAsteroidesCrees < 2)) { listeAsteroides->push_back(new StrongAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbStrongAsteroidesCrees++; }
			(*vjeu)[0]->nbAsteroidesACreer = 7;
			break;
		case 4 :
			if ((nbTicks % (nbm + 6064) == 0) && ((*vjeu)[0]->nbLowAsteroidesCrees < 2)) { listeAsteroides->push_back(new LowAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbLowAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 6064) == 0) && ((*vjeu)[0]->nbStrongAsteroidesCrees < 1)) { listeAsteroides->push_back(new StrongAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbStrongAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 6064) == 0) && ((*vjeu)[0]->nbFastAsteroidesCrees < 1)) { listeAsteroides->push_back(new FastAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbFastAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 6064) == 0) && ((*vjeu)[0]->nbLowAsteroidesCrees < 3)) { listeAsteroides->push_back(new LowAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbLowAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 6064) == 0) && ((*vjeu)[0]->nbStrongAsteroidesCrees < 2)) { listeAsteroides->push_back(new StrongAsteroide((*cDamier)[0]->getnbL(),1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbStrongAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 6064) == 0) && ((*vjeu)[0]->nbFastAsteroidesCrees < 2)) { listeAsteroides->push_back(new FastAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbFastAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 6064) == 0) && ((*vjeu)[0]->nbStrongAsteroidesCrees < 3)) { listeAsteroides->push_back(new StrongAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbStrongAsteroidesCrees++; }
			
			else if ((nbTicks % (nbm + 6064) == 0) && ((*vjeu)[0]->nbLowAsteroidesCrees < 5)) { listeAsteroides->push_back(new LowAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbLowAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 6064) == 0) && ((*vjeu)[0]->nbStrongAsteroidesCrees < 4)) { listeAsteroides->push_back(new StrongAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbStrongAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 6064) == 0) && ((*vjeu)[0]->nbFastAsteroidesCrees < 3)) { listeAsteroides->push_back(new FastAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbFastAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 6064) == 0) && ((*vjeu)[0]->nbLowAsteroidesCrees < 6)) { listeAsteroides->push_back(new LowAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbLowAsteroidesCrees++; }
			else if ((nbTicks % (nbm + 6064) == 0) && ((*vjeu)[0]->nbStrongAsteroidesCrees < 6)) { listeAsteroides->push_back(new StrongAsteroide((*cDamier)[0]->getnbL(), 1, listeAsteroides, listeAsteroides->size())); (*vjeu)[0]->nbStrongAsteroidesCrees++; }

			(*vjeu)[0]->nbAsteroidesACreer = 15;
			break;


		}
	}
	

	nbTicks += 1;
	if ((*vjeu)[0]->getPartieLancee()) {
		if (nbTicks % (2308 / frequence) == 0) newMissile();
	}

	for (int j = 0; j < listeAsteroides->size(); j++) {
		if (getY2() == (*listeAsteroides)[j]->getY()) {
			if (getX2() > (*listeAsteroides)[j]->getX()) {
				(*listeMissiles)[0]->setPartieFinie(true);
				bo = true;
				(*vjeu)[0]->setPartieLancee(false);
				(*vjeu)[0]->setMessageFin("Vous avez perdu...");
				(*vjeu)[0]->setAfficherMessageFin(true);
			}
		}
		else if ((*listeAsteroides)[j]->getX() <= -0.3f) {
			(*listeMissiles)[0]->setPartieFinie(true);
			bo = true;
			(*vjeu)[0]->setPartieLancee(false);
			(*vjeu)[0]->setMessageFin("Vous avez perdu...");
			(*vjeu)[0]->setAfficherMessageFin(true);
		}

	}
	std::cout << std::endl;

	if ((*listeMissiles)[0]->getPartieFinie()){
		(*listeVaisseaux).clear();
		(*vjeu)[0]->setPartieLancee(false);
		bo = true;
		(*listeMissiles)[0]->setPartieFinie(false);
	}
}