#include "Fourmis.h"

void Fourmis::draw() {
	GraphicPrimitives::drawFillTriangle2D(x1, y1, x2, y2, x3, y3, r, g, b, a);
}