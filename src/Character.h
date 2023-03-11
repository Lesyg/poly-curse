#ifndef TERMWORK_CHARACTER_H
#define TERMWORK_CHARACTER_H

#include "Window.h"
#include <memory>
#include <queue>

class Character {
public:
	/**
	 * Basic constructor for Character class
	 * @param y coordinate Y
	 * @param x coordinate X
	 * @param dmg damage
	 * @param hp health points
	 */
	Character(int y, int x, int dmg, int hp)
	: corY(y), corX(x), damage(dmg), healthPoints(hp) {};
	/**
	 * Virtual Character destructor
	 */
	virtual ~Character() = default;
	/**
	 * Method that handles character movement
	 * @param window Window class on which the game takes place
	 * @param key pressed key
	 * @param characters vector of characters need for damage system
	 */
	virtual void move(const Window &window, chtype key, std::vector<std::shared_ptr<Character>> &characters) = 0;
	/**
	 * Method that handles characters attack actions
	 * @param characters vector of characters need to damage system
	 */
	virtual void attack(std::vector<std::shared_ptr<Character>> &characters) = 0;
	/**
	 * Decreases the health points by damage taken from player
	 * @param damage dealt by a player
	 */
	virtual void takeDamageFromPlayer (int damage) = 0;
	/**
	 * Decreases the health points by damage taken from enemy
	 * @param damage dealt by an enemy
	 */
	virtual void takeDamageFromEnemy (int damage) = 0;
	/**
	 * Draws the character in the correct coordinates and
	 * with the correct color
	 * @param window to which the character is drawn to
	 */
	virtual void draw(const Window &window) = 0;
	/**
	 * Writes information about the character into a output stream
	 * using a virtual print method
	 * @param output takes ostream as input
	 * @param character const reference to an object
	 * @return return inputted output stream
	 */
	friend std::ostream& operator << (std::ostream & output, Character &character);
	/**
	 * Outputs the actual information to output stream
	 * is needed due to the limitations of << operator
	 * @param output
	 */
	virtual void print(std::ostream & output) const = 0;
	/**
	 * Getter for coordinate Y
	 * @return coordinate Y
	 */
	int getCorY () const;
	/**
	 * Getter for coordinate X
	 * @return coordinate X
	 */
	int getCorX () const;
	/**
	 * Getter for damage
	 * @return damage
	 */
	int getHealthPoints () const;
	/**
	 * Getter for doMine
	 * if doMien is true it sets it to false
	 * is implemented this way to force the player to mine only once after pressing
	 * the key for mining
	 * @return returns doMine
	 */
	bool getMine ();
	/**
	 * Getter for direction of character
	 * @return direction on Y axis
	 */
	int getDirY () const;
	/**
	 * Getter for direction of character
	 * @return direction on X axis
	 */
	int getDirX() const;
	/**
	 * Getter for doPlace
	 * if doPlace is true it sets it to false
	 * is implemented this way to force the player to place only one block at a time
	 * @return returns doPlace
	 */
	bool getPlace ();
	/**
	 * Calculates the distance between two characters
	 * @param y coordinate Y of other character
	 * @param x coordinate X of other character
	 * @return returns the distance
	 */
	int distance (int y, int x) const;
	/**
	 * Method that checks whether or not the character can advance
	 * to the next position
	 * @param y direction Y
	 * @param x direction X
	 * @param window on which the game takes place
	 * @return returns true if there is not a block or the block is liquid
	 */
	bool canMove(int y, int x, const Window &window) const;
	/**
	 * Adds mined item to inventory
	 * @param item name
	 */
	void addToInv(const std::string &item);
	/**
	 * Removes the item from inventory
	 * @return returns the item that is removed
	 */
	std::string popFromInv ();
	/**
	 * Cleans up all that belongs to a character
	 * @param window where the game takes place
	 */
	virtual void clean(const Window &window) const = 0;
	/**
	 * Draws the character in the correct coordinates
	 * using the correct color
	 * @param window takes window object to which the block will be drawn
	 */
	void unDraw(const Window &window) const;
protected:
	/**
	 * Handles gravity and fall damage interaction
	 * @param window
	 */
	void gravity (const Window &window);
	int corY, corX;
	int damage;
	int healthPoints;
	int dirX = 0, dirY = 0;
	int fallDamage = 0;
	//integer that controls the move frequency
	int moveFrequency = 1;
	bool doMine = false, doPlace = false, canJump = false, canFall = true;
	std::queue<std::string> inventory;

private:

};

#endif //TERMWORK_CHARACTER_H