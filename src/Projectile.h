#ifndef TERMWORK_PROJECTILE_H
#define TERMWORK_PROJECTILE_H

#include "Enemy.h"

class Projectile : public Enemy {
public:
	/**
	 * Basic constructor
	 * @param y coordinate Y
	 * @param x coordinate X
	 * @param dmg damage
	 * @param hp health points
	 */
	Projectile(int y, int x, int dmg, int hp) : Enemy(y, x, dmg, hp) {};
	/**
	 * Default destructor
	 */
	~Projectile() override = default;
	/**
	 * Method for outputting the information about player to a file
	 * @param output stream to write attributes into
	 */
	void print(std::ostream & output) const override {};
	/**
	 * Method that moves the projectile by one to the left or right
	 * @param window where the game takes place
	 * @param key direction of the projectile
	 * @param characters vector of characters needed for combat system
	 */
	void move (const Window &window, chtype ch, std::vector<std::shared_ptr<Character>> &characters) override;
	/**
	* Method that performs an attack on the player if it connects
	* @param characters vector of characters needed to inflict damage to the player
	*/
	void attack (std::vector<std::shared_ptr<Character>> &characters) override;
	/**
	 * Cannot take damage therefore the method is empty
	 * @param damage
	 */
	void takeDamageFromEnemy (int damage) override {};
	/**
	 * Cannot take damage therefore the method is empty
	 * @param damage
	 */
	void takeDamageFromPlayer (int damage) override {};
	/**
	 * Draws the projectile to the window in the correct coordinates and
	 * with the correct color
	 * @param window where the game takes place
	 */
	void draw(const Window &window) override;
	/**
	 * Removes the item from inventory
	 * @return returns the item that is removed
	 */
	void clean(const Window &window) const override;

private:
	int direction = 0;
};

#endif //TERMWORK_PROJECTILE_H