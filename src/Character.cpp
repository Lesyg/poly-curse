#include "Character.h"

bool Character::canMove (int y, int x, const Window &window) const {
	chtype color = window.getColorAt (y, x);
	chtype text = window.getCharAt (y, x);
	if ((color == COLOR_PAIR(WINDOW_BG) || color == COLOR_PAIR(LAVA) || color == COLOR_PAIR(WATER))  && text == ' ') {
		return true;
	}
	return false;
}

int Character::distance (int y, int x) const {
	return int(sqrt((y-corY)*(y-corY) + (x-corX)*(x-corX)));
}

void Character::unDraw (const Window &window) const {
	wattron(window.getWindow(), COLOR_PAIR (WINDOW_BG));
	window.addAt (corY, corX, " ");
	wattroff(window.getWindow(), COLOR_PAIR (WINDOW_BG));
}

std::ostream &operator<< (std::ostream &output, Character &character) {
	character.print(output);
	return output;
}

bool Character::getPlace () {
	if (doPlace) {
		doPlace = false;
		return true;
	}
	return doPlace;
}

bool Character::getMine () {
	if (doMine) {
		doMine = false;
		return true;
	}
	return doMine;
}

void Character::gravity (const Window &window) {
	if (fallDamage > DAMAGE_FROM_HEIGHT && !canMove (corY+1, corX, window)) {
		healthPoints -= fallDamage/2;
		fallDamage = 0;
	}
	if (!canMove (corY+1, corX, window)) {
		canJump = true;
		fallDamage = 0;
	}
	if (canMove (corY +1, corX, window) && canFall) {
		corY++;
		fallDamage++;
	}
}

int Character::getCorY () const {
	return corY;
}

int Character::getCorX () const {
	return corX;
}

int Character::getHealthPoints () const {
	return healthPoints;
}

int Character::getDirY () const {
	return dirY;
}

int Character::getDirX () const {
	return dirX;
}

void Character::addToInv (const std::string &item) {
	if (item == " ") {
		return;
	}
	inventory.push (item);
}

std::string Character::popFromInv () {
	if (inventory.empty()) {
		return " ";
	}
	std::string item = inventory.front();
	inventory.pop();
	return item;
}
