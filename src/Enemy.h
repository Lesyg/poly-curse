#ifndef TERMWORK_ENEMY_H
#define TERMWORK_ENEMY_H

#include "Character.h"

class Enemy : public Character {
public:
	/**
	 * Basic constructor
	 * @param y coordinate Y
	 * @param x coordinate X
	 * @param dmg damage
	 * @param hp health points
	 */
	Enemy(int y, int x, int dmg, int hp) : Character(y, x, dmg, hp) {};
	/**
	 * Finds the player on a map
	 * hiding in a liquid servers as protection from enemy vision
	 * upon not finding the player an enemy navigates to the middle
	 * @param window on which the game is played
	 * @param[out] corY returns y coordinate of player
	 * @param[out] corX returns x coordinate of player
	 */
	void findPlayer(const Window &window, int * corY, int * corX);
};

#endif //TERMWORK_ENEMY_H