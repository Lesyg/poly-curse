#ifndef TERMWORK_DIRT_H
#define TERMWORK_DIRT_H

#include "Solid.h"

class Dirt : public Solid{
public:
	/**
	 * Basic constructor
	 * @param y coordinate Y
	 * @param x coordinate X
	 */
	Dirt (int y, int x) : Solid (y, x) {};
	/**
	 * Basic destructor
	 */
	~Dirt() override = default;
	/**
	 * Prints the coordinates of the dirt block into a file
	 * @param output stream to which the information is written
	 */
	void print (std::ostream &output) const override;
	/**
	 * Draws block at the correct coordinates and
	 * with the correct color
	 * @param window where the game takes place
	 */
	void draw (const Window &window) const override;
	/**
	 * Removes the item from inventory
	 * @return returns the item that is removed
	 */
	std::string type() const override;

private:

};

#endif //TERMWORK_DIRT_H