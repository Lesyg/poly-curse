#include "Projectile.h"

void Projectile::attack (std::vector<std::shared_ptr<Character>> &characters) {
	for (const auto &it : characters) {
		if (it->getCorY() == corY && it->getCorX() == corX) {
			it->takeDamageFromEnemy (5);
		}
	}
}

void Projectile::move (const Window &window, chtype ch, std::vector<std::shared_ptr<Character>> &characters) {
	unDraw (window);
	if (ch == '-') {
		direction = -1;
	} else if (ch == '+') {
		direction = 1;
	}
	corX += direction;

	attack (characters);
	draw(window);
}

void Projectile::draw (const Window &window) {
	wattron(window.getWindow(), COLOR_PAIR (WINDOW_BG));
	window.addAt (corY, corX, BULLET);
	wattron(window.getWindow(), COLOR_PAIR (WINDOW_BG));
}

void Projectile::clean (const Window &window) const {
	unDraw (window);
}
