#pragma once
#include "GraphicPrimitives.h"
#include "Asteroide.h"
#include "CaseDamier.h"
#include "ObjetsAandM.h"
#include <string>

class VariablesDeJeu {
private :
	boolean partieLancee;
	std::string partie = "Lancer la partie";
	int difficulte = 0;
	int argent;
	boolean speedV = false;
	boolean lowV = false;
	boolean mediumV = false;

	boolean creationAste = false;

	boolean afficherMessageFin = false;
	std::string messageFin = "";
	boolean afficherMessagePlusDeVaisseauxAPoser = false;
	std::string messagePlusDeVaisseauxAPoser = "Vous n'avez plus ce type de vaisseaux...Veuillez en acheter :)";


	int nbLowVAchetes = 0;
	int nbMediumVAchetes = 0;
	int nbSpeedVAchetes = 0;

	int nbLowVPoses = 0;
	int nbMediumVPoses = 0;
	int nbSpeedVPoses = 0;

	boolean menuDifficulteDeroule = false;
	boolean difficulteChoisie[5] = { false };


	std::vector<float> listexf;
	std::vector<float> listeyf;
	std::vector<float> listexa;
	std::vector<float> listeya;
	std::vector<float> listeXl;
	std::vector<float> listeYl;
	std::vector<float> listeXM;
	std::vector<float> listeYM;
	std::vector<float> listeXS;
	std::vector<float> listeYS;

	ObjetsAandM *o = new ObjetsAandM(1.0f,1.0f, 1,1,1,1);

public:
	VariablesDeJeu() : partieLancee(false), argent(20){
		/**Initialisation des talbeaux ligneOccupee et VaisseauDejaPoseSurLaCase**/
		listexf = o->creaListeX(-0.3f, 1);
		listeyf = o->creaListeY(0.355f, 1);
		listexa = o->creaListeX(-0.58f, 1);
		listeya = o->creaListeY(0.32f,1);
		listeXl = o->creaListeX(-0.58f, 1);
		listeYl = o->creaListeY(0.045f, 1);
		listeXM = o->creaListeX(-0.58f, 1);
		listeYM = o->creaListeY(-0.15f, 1);
		listeXS = o->creaListeX(-0.58f, 1);
		listeYS = o->creaListeY(-0.35f, 1);

		reinitializeTabs();
		reinitializeDifficulte();
	}

	boolean vaisseauDejaPoseSurLaCase[20][20] = { {false} };
	boolean ligneOccupee[20] = { false };

	int score = 0;
	int meilleurScore = 0;

	int nbLowAsteroidesCrees = 0;
	int nbFastAsteroidesCrees = 0;
	int nbStrongAsteroidesCrees = 0;

	int higherDiff = 0;
	int nbAsteroidesACreer = 0;

	//Fonctions
	void draw();
	void ticks();

	boolean getPartieLancee() {
		return partieLancee;
	}
	void setPartieLancee(boolean b) {
		partieLancee = b;
		if (b) { partie = "GO"; setCreationAste(true);score = 0; }
		else { partie = "Lancer la partie"; reinitializeTabs(); setnbLPoses(0); setnbMPoses(0); setnbSPoses(0); nbAsteroidesACreer = 0; nbLowAsteroidesCrees = 0; nbFastAsteroidesCrees = 0; nbStrongAsteroidesCrees = 0; setCreationAste(false); }
	}

	void dessinTriangle(float x1, float x2, float r, float g, float b, float a);

	boolean getSpeedV() { return speedV; }
	boolean getLowV() { return lowV; }
	boolean getMediumV() { return mediumV; }
	
	void setSpeedV(boolean b) { speedV = b; }
	void setLowV(boolean b) { lowV = b; }
	void setMediumV(boolean b) { mediumV = b; }

	void reinitializeTabs();

	boolean getMenuDifficulteDeroule() {
		return menuDifficulteDeroule;
	}
	void setMenuDifficulteDeroule(boolean b) {
		menuDifficulteDeroule = b;
	}
	
	boolean* getDifficulteChoisie() {
		return difficulteChoisie;
	}
	void setDifficulteChoisie(int j, boolean b) {
		difficulteChoisie[j] = b;
		difficulte = j;
	}

	int getDifficulte() {
		return difficulte;
	}
	void reinitializeDifficulte();

	int getArgent() {
		return argent;
	}
	void setArgent(int n) {
		argent = n;
	}

	int getnbLAchetes() {
		return nbLowVAchetes;
	}
	void setnbLAchetes(int n) {
		nbLowVAchetes = n;
	}
	int getnbMAchetes() {
		return nbMediumVAchetes;
	}
	void setnbMAchetes(int n) {
		nbMediumVAchetes = n;
	}
	int getnbSAchetes() {
		return nbSpeedVAchetes;
	}
	void setnbSAchetes(int n) {
		nbSpeedVAchetes = n;
	}

	int getnbLPoses() {
		return nbLowVPoses;
	}
	void setnbLPoses(int n) {
		nbLowVPoses = n;
	}
	int getnbMPoses() {
		return nbMediumVPoses;
	}
	void setnbMPoses(int n) {
		nbMediumVPoses = n;
	}
	int getnbSPoses() {
		return nbSpeedVPoses;
	}
	void setnbSPoses(int n) {
		nbSpeedVPoses = n;
	}

	std::string getMessageFin() {
		return messageFin;
	}
	void setMessageFin(std::string s) {
		messageFin = s;
	}
	boolean getAfficherMessageFin() {
		return afficherMessageFin;
	}
	void setAfficherMessageFin(boolean b) {
		afficherMessageFin = b;
	}
	

	void setAfficherMessagePlusDeVaisseauxAPoser(boolean b) {
		afficherMessagePlusDeVaisseauxAPoser = b;
	}
	boolean getAfficherMessagePlusDeVaisseauxAPoser() {
		return afficherMessagePlusDeVaisseauxAPoser;
	}
	void setMessagePlusDeVaisseauxAPoser(std::string s) {
		messagePlusDeVaisseauxAPoser = s;
	}
	std::string getMessagePlusDeVaisseauxAPoser() {
		return messagePlusDeVaisseauxAPoser;
	}

	boolean getCreationAste(){
		return creationAste;
	}
	void setCreationAste(boolean b) {
		creationAste = b;
	}
};
