#include "Ranged.h"

void Ranged::move (const Window &window, const chtype ch, std::vector<std::shared_ptr<Character>> &characters) {
	int pY = 0;
	int pX = 0;
	findPlayer (window, &pY, &pX);
	unDraw (window);
	gravity (window);
	draw (window);

	if (distance(pY, pX) > AGRO_RANGE/2 && moveFrequency % 2) {
		if (randomInt(0, 100) > 75) {
			projectiles.push_back (std::make_shared<Projectile>(corY, corX, 5, 1));
			if (pX - corX < 0) {
				projectiles.back()->move (window, '-', characters);
			} else {
				projectiles.back()->move (window, '+', characters);
			}
		}
		std::vector<std::shared_ptr<Projectile>>::iterator it;
		it = projectiles.begin();
		while (it != projectiles.end()) {
			if (!((*it)->canMove ((*it)->getCorY(), (*it)->getCorX()+1, window))) {
				(*it)->move (window, ' ', characters);
				(*it)->unDraw (window);
				it = projectiles.erase (it);
				continue;
			}
			(*it)->move (window, ' ', characters);
			it++;
		}
		return;
	}
	unDraw (window);
	if ((corX - pX) != 0 && moveFrequency % 2) {
		int tmpX = pX - corX;
		if (canMove(corY, corX - tmpX/abs(tmpX), window)) {
			corX -= tmpX/abs(tmpX);
			canFall = true;
		} else if (canMove (corY-1, corX, window)) {
			corY--;
			canFall = false;
		}
	}
	for (const auto & it : projectiles) {
		it->move (window, '-', characters);
	}
	moveFrequency++;
	draw (window);
}

void Ranged::attack (std::vector<std::shared_ptr<Character>> &characters) {
}

void Ranged::takeDamageFromPlayer (int damage) {
	healthPoints -= damage;
}

void Ranged::draw (const Window &window) {
	wattron(window.getWindow(),COLOR_PAIR (RANGED));
	window.addAt (corY, corX, "T");
	wattroff(window.getWindow(), COLOR_PAIR (RANGED));
}

void Ranged::print (std::ostream &output) const {
	output << RANGED_CH << " " << corY << " " << corX << " " << healthPoints << " " << damage;
}

void Ranged::clean (const Window & window) const {
	for (auto &it : projectiles) {
		it->unDraw (window);
	}
	unDraw(window);
}