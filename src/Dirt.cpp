#include "Dirt.h"

void Dirt::print (std::ostream &output) const {
	output << DIRT_CH << " " << corY << " " << corX;
}

void Dirt::draw (const Window &window) const {
	wattron(window.getWindow(),COLOR_PAIR (DIRT));
	window.addAt (corY, corX, " ");
	wattroff(window.getWindow(), COLOR_PAIR (DIRT));
}

std::string Dirt::type () const {
	return DIRT_CH;
}
