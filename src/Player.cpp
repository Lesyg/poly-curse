#include "Player.h"

void Player::move (const Window &window, const chtype ch, std::vector<std::shared_ptr<Character>> &characters) {
	if (window.getColorAt (corY+1, corX) == COLOR_PAIR(LAVA) || window.getColorAt (corY, corX) == COLOR_PAIR(LAVA)) {
		takeDamageFromEnemy (7);
	}
	if (window.getColorAt (corY, corX) == COLOR_PAIR(WATER)) {
		if (underWater > 4) {
			takeDamageFromEnemy (1);
		}
		underWater++;
	} else {
		underWater = 0;
	}
	unDraw (window);
	gravity (window);
	handleInput (ch, window, characters);
	draw (window);
	printUI (window);
	//upon the death of the player all characters are erased as a signal that the game has ended
	if (healthPoints <= 0) {
		characters.clear();
	}
}

void Player::attack (std::vector<std::shared_ptr<Character>> &characters) {
	for (const auto &it : characters) {
		if (((distance (it->getCorY(), it->getCorX()) <= 4)) && ((it->getCorY() != corY || it->getCorX() != corX))) {
			it->takeDamageFromPlayer(damage);
		}
	}
}

void Player::takeDamageFromEnemy (int damage) {
	healthPoints -= damage;
}

void Player::draw (const Window &window) {
	wattron(window.getWindow(),COLOR_PAIR (PLAYER));
	window.addAt (corY, corX, PLAYER_MD);
	wattroff(window.getWindow(), COLOR_PAIR (PLAYER));
}

void Player::print (std::ostream &output) const {
	output << PLAYER_CH << " " << corY << " " << corX << " " << healthPoints << " " << damage;
}

void Player::handleInput (chtype ch, const Window &window, std::vector<std::shared_ptr<Character>> &characters) {
	if (ch != (unsigned)ERR) {
		switch (ch) {
			case LEFT:
				if (canMove (corY, corX - 1, window)) {
					corX--;
				}
				canFall = true;
				dirX = corX-1;
				dirY = corY;
				break;
			case DOWN:
				canFall = true;
				dirY = corY+1;
				dirX = corX;
				break;
			case RIGHT:
				if (canMove (corY, corX + 1, window)) {
					corX++;
				}
				canFall = true;
				dirX = corX+1;
				dirY = corY;
				break;
			case ATTACK:
				canFall = true;
				attack(characters);
				break;
			case JUMP:
				if (canMove (corY - 1, corX, window) && canJump) {
					corY--;
					canJump = false;
					canFall = false;
				}
				dirY = corY-1;
				dirX = corX;
				break;
			case MINE:
				canFall = true;
				doMine = true;
				break;
			case PLACE:
				canFall = true;
				doPlace = true;
				break;
			case MEDITATE:
				if (healthPoints < PLAYER_HP) {
					healthPoints++;
				}
			default:
				break;
		}
	}
}

void Player::printUI (const Window &window) const {
	wattron(window.getWindow(), COLOR_PAIR (WINDOW_BG));
	std::string tmp = "x: " + std::to_string (corX) + " y: " + std::to_string (corY);
	tmp += " HP: " + std::to_string (healthPoints) + "  ";
	window.addAt(0, 1,tmp);
	wattroff(window.getWindow(), COLOR_PAIR (WINDOW_BG));
}

void Player::clean (const Window &window) const {
	unDraw (window);
}