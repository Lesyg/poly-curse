#ifndef TERMWORK_RANGED_H
#define TERMWORK_RANGED_H

#include "Enemy.h"
#include "Projectile.h"

class Ranged : public Enemy {
public:
	/**
	 * Basic constructor that initializes coordinates and player attributes
	 * @param y coordinate Y
	 * @param x coordinate X
	 * @param dmg damage
	 * @param hp health points
	 */
	Ranged(int y, int x, int dmg, int hp) : Enemy(y, x, dmg, hp) {};
	/**
 	 * Default destructor
	 */
	~Ranged() override = default;
	/**
	 * Method for outputting the information about player to a file
	 * @param output stream to write attributes into
	 */
	void print(std::ostream & output) const override;
	/**
	 * Method that moves the character based on distance from the player
	 * doesn't move until the player is too close and then tries to run from the player
	 * @param window where the game takes place
	 * @param key key pressed by the user
	 * @param characters vector of characters needed for combat system
	 */
	void move (const Window &window, chtype ch, std::vector<std::shared_ptr<Character>> &characters) override;
	/**
	 * Method that performs a ranged attack on the player
	 * @param characters vector of characters needed to inflict damage to the player
	 */
	void attack (std::vector<std::shared_ptr<Character>> &characters) override;
	/**
	 * Enemy cannot take damage from himself or other enemies therefore the method is empty
	 * @param damage taken
	 */
	void takeDamageFromEnemy (int damage) override {}
	/**
	 * Enemy takes damage from player
	 * @param damage caused by the enemy
	 */
	void takeDamageFromPlayer (int damage) override;
	/**
	 * Draws the character to the window in the correct coordinates and
	 * with the correct color
	 * @param window where the game takes place
	 */
	void draw(const Window &window) override;
	/**
	 * Cleans up all that is needed to be cleaned up
	 * @return returns the item that is removed
	 */
	void clean (const Window & window) const override;

private:
	std::vector<std::shared_ptr<Projectile>> projectiles;
};

#endif //TERMWORK_RANGED_H