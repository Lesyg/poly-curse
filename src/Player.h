#ifndef TERMWORK_PLAYER_H
#define TERMWORK_PLAYER_H

#include "Character.h"

class Player : public Character {
public:
	/**
	 * Basic constructor that initializes coordinates and player attributes
	 * @param y coordinate Y
	 * @param x coordinate X
	 * @param dmg damage
	 * @param hp health points
	 */
	Player(int y, int x, int dmg, int hp)
	: Character(y, x, dmg, hp) {};
	/**
	 * Default destructor
	 */
	~Player() override = default;
	/**
	 * Method for outputting the information about player to a file
	 * @param output stream to write attributes into
	 */
	void print(std::ostream & output) const override;
	/**
	 * Method that handles user input and player movement
	 * @param window where the game takes place
	 * @param key key pressed by the user
	 * @param characters vector of characters needed for combat system
	 */
	void move(const Window &window, chtype key, std::vector<std::shared_ptr<Character>> &characters) override;
	/**
	 * Method that performs an attack on all nearby enemies
	 * @param characters vector of characters needed to find enemies within striking distance
	 */
	void attack(std::vector<std::shared_ptr<Character>> &characters) override;
	/**
	 * Player takes damage from enemy
	 * @param damage caused by the enemy
	 */
	void takeDamageFromEnemy (int damage) override;
	/**
	 * Player cannot take damage from himself therefore the method is empty
	 * @param damage taken
	 */
	void takeDamageFromPlayer (int damage) override {}
	/**
	 * Draws the player to the window in the correct coordinates and
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
	/**
	 * Handles user input as movement of the player
	 * @param key key
	 * @param window where the game takes place
	 * @param characters enemies
	 */
	void handleInput (chtype ch, const Window &window, std::vector<std::shared_ptr<Character>> &characters);
	/**
	 * Prints information about the player
	 * @param window
	 */
	void printUI (const Window &window) const;
	int underWater = 0;
};

#endif //TERMWORK_PLAYER_H