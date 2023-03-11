#include "Stone.h"

void Stone::print (std::ostream &output) const {
	output << STONE_CH << " " << corY << " " << corX;
}

void Stone::draw (const Window &window) const {
	wattron(window.getWindow(),COLOR_PAIR (STONE));
	window.addAt (corY, corX, " ");
	wattroff(window.getWindow(), COLOR_PAIR (STONE));
}

std::string Stone::type () const {
	return STONE_CH;
}
