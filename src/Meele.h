#ifndef TERMWORK_MEELE_H
#define TERMWORK_MEELE_H

#include "Enemy.h"

class Meele : public Enemy {
public:
	/**
	 * Basic constructor
	 * @param y coordinate y
	 * @param x coordinate x
	 * @param dmg character damage
	 * @param hp character health points
	 */
	Meele(int y, int x, int dmg, int hp) : Enemy(y, x, dmg, hp) {};
	/**
	 * Default destructor
	 */
	~Meele() override = default;
	/**
	 * Prints the information about the block to output stream
	 * @param output
	 */
	void print(std::ostream & output) const override;
	/**
	 * Handles the movement of the character
	 * @param window where the game takes place
	 * @param keyPressed
	 * @param characters vector of characters that is needed for calculations
	 * and damage system
	 */
	void move (const Window &window, chtype keyPressed, std::vector<std::shared_ptr<Character>> &characters) override;
	/**
	 * Enemy cannot take damage from another enemy
	 * @param damage outputted
	 */
	void takeDamageFromEnemy (int damage) override {}
	/**
	 * Decreases the health points by damage
	 * @param damage taken from player
	 */
	void takeDamageFromPlayer (int damage) override;
	/**
	 * Draws the character at the correct coordinates and
	 * with the correct colors
	 * @param window where the game takes place
	 */
	void draw(const Window &window) override;
	/**
	 * Cleans up all junk on the screen
	 * @param window that will be cleaned
	 */
	virtual void clean(const Window &window) const override;

private:
	/**
	 * Attacks all players that are near enough
	 * @param characters
	 */
	void attack (std::vector<std::shared_ptr<Character>> &characters) override;
};

#endif //TERMWORK_MEELE_H