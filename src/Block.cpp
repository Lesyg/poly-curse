#include "Block.h"

//TODO improve liquid block behavior

bool Block::operator== (const Block &block) const {
	return corY == block.corY && corX == block.corX;
}

std::ostream &operator<< (std::ostream &output, Block &block) {
	block.print(output);
	return output;
}

int Block::getCorX () const {
	return corX;
}

int Block::getCorY () const {
	return corY;
}

void Block::unDraw (const Window &window) const {
	wattron(window.getWindow(), COLOR_PAIR (WINDOW_BG));
	window.addAt (corY, corX, " ");
	wattroff(window.getWindow(), COLOR_PAIR (WINDOW_BG));
}