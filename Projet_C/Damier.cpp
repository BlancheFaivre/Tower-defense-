#include "Damier.h"

void Damier::draw() {
	for (int i = 0; i < vCaseDamier->size(); i++) {
		(*vCaseDamier)[i]->draw();
	}
}
