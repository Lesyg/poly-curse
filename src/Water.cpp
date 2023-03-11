#include "Water.h"

void Water::draw (const Window &window) const {
	wattron(window.getWindow(),COLOR_PAIR (WATER));
	window.addAt (corY, corX, " ");
	wattroff(window.getWindow(), COLOR_PAIR (WATER));
}

void Water::print (std::ostream &output) const {
	output << WATER_CH << " " << corY << " " << corX;
}

std::string Water::type () const {
	return WATER_CH;
}
