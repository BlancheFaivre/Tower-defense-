#include "CaseDamier.h"

void CaseDamier::draw() {
	for (int i = 0; i < nbLignes; i++) {
		GraphicPrimitives::drawOutlinedRect2D(-0.3f + cpt2, -0.1f - 0.2f * i, 0.1f, 0.2f, 100.0f, 100.0f, 100.0f, 100.0f);
	}
}