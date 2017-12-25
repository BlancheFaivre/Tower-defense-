#include "MyGameEngine.h"

void MyGameEngine::idle() {
	for (int i = 0; i < missile->size(); i++) {
	(*missile)[i]->tick();
	}
	for (int i = 0; i < vaisseaux->size(); i++) {
		(*vaisseaux)[i]->tick();
	}
	for (int i = 0; i < asteroide->size(); i++) {
		(*asteroide)[i]->tick();
	}
}
