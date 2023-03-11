#ifndef TERMWORK_STONE_H
#define TERMWORK_STONE_H

#include "Solid.h"

class Stone : public Solid {
public:
	/**
	 * Basic constructor
	 * @param y coordinate Y
	 * @param x coordinate X
	 */
	Stone(int y, int x) : Solid (y, x) {};
	/**
	 * Basic destructor
	 */
	~Stone() override = default;
	/**
	 * Prints the coordinates of the stone block into a file
	 * @param output
	 */
	void print (std::ostream &output) const override;
	/**
	 * Draws th stone block at the correct coordinates and
	 * with the correct color
	 * @param window where the game takes place
	 */
	void draw (const Window &window) const override;
	/**
	 * Returns the item type
	 * @return string type
	 */
	std::string type() const override;

private:
};

#endif //TERMWORK_STONE_H