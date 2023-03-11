#ifndef TERMWORK_WATER_H
#define TERMWORK_WATER_H

#include "Liquid.h"

class Water : public Liquid{
public:
	/**
	 * Basic constructor
	 * @param y coordinate Y
	 * @param x coordinate X
	 */
	Water (int y, int x) : Liquid (y, x) {};
	/**
	 * Default destructor
	 */
	~Water() override = default;
	/**
	 * Draws water block at the correct coordinates and
	 * with the correct color
	 * @param window where the game takes place
 	*/
	void draw (const Window &window) const override;
	/**
	 * Prints the coordinates of the water block into a file
	 * @param output the stream in which the information is inputted
	 */
	void print (std::ostream &output) const override;
	/**
	 * Returns the block type
	 * @return string type
	 */
	std::string type() const override;

private:
};

#endif //TERMWORK_WATER_H