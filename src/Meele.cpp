#include "Meele.h"

void Meele::move (const Window &window, const chtype ch, std::vector<std::shared_ptr<Character>> &characters) {
	int pY, pX = 0;
	findPlayer (window, &pY, &pX);
	unDraw (window);
	gravity (window);
	draw (window);
	if (distance(pY, pX) > AGRO_RANGE) {
		return;
	}
	unDraw (window);
	if (distance (pY, pX) < ATTACK_RANGE) {
		attack(characters);
	}
	if ((corX - pX) != 0 && moveFrequency % 2) {
		int tmpX = pX - corX;
		if (canMove(corY, corX + tmpX/abs(tmpX), window)) {
			corX += tmpX/abs(tmpX);
			canFall = true;
		} else if (canMove (corY-1, corX, window)) {
			corY--;
			canFall = false;
		}
	}
	moveFrequency++;
	draw (window);
}

void Meele::attack (std::vector<std::shared_ptr<Character>> &characters) {
	for (const auto &it : characters) {
		if ((it->getCorY() != corY || it->getCorX() != corX)) {
			it->takeDamageFromEnemy(damage);
		}
	}
}

void Meele::takeDamageFromPlayer (int damage) {
	healthPoints -= damage;
}

void Meele::draw (const Window &window) {
	wattron(window.getWindow(),COLOR_PAIR (MEELE));
	window.addAt (corY, corX, "A");
	wattroff(window.getWindow(), COLOR_PAIR (MEELE));
}

void Meele::print (std::ostream &output) const {
	output << MEELE_CH << " " << corY << " " << corX  << " " << healthPoints << " " << damage;
}

void Meele::clean (const Window &window) const {
	unDraw (window);
}