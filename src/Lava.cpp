#include "Lava.h"

void Lava::draw (const Window &window) const {
	wattron(window.getWindow(),COLOR_PAIR (LAVA));
	window.addAt (corY, corX, " ");
	wattroff(window.getWindow(), COLOR_PAIR (LAVA));
}

void Lava::print (std::ostream &output) const {
	output << LAVA_CH << " " << corY << " " << corX;
}

std::string Lava::type () const {
	return LAVA_CH;
}
