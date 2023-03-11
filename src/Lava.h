#ifndef TERMWORK_LAVA_H
#define TERMWORK_LAVA_H

#include "Liquid.h"

class Lava : public Liquid {
public:
	/**
	 * Basic constructor
	 * @param y coordinate Y
	 * @param x coordinate X
	 */
	Lava (int y, int x) : Liquid (y, x) {};
	/**
	 * Default destructor
	 */
	~Lava() override = default;
	/**
	 * Draws ;ava block at the correct coordinates and
	 * with the correct color
	 * @param window where the game takes place
 	*/
	void draw (const Window &window) const override;
	/**
	 * Prints the coordinates of the lava block into a file
	 * @param output the stream in which the information is inputted
	 */
	void print (std::ostream &output) const override;
	/**
	 * Removes the item from inventory
	 * @return returns the item that is removed
	 */
	std::string type() const override;

private:
};

#endif //TERMWORK_LAVA_H