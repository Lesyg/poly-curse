#ifndef TERMWORK_SOLID_H
#define TERMWORK_SOLID_H

#include "Block.h"

class Solid : public Block {
public:
	/**
	 * Basic constructor
	 * @param y coordinate Y
	 * @param x coordinate X
	 */
	Solid(int y, int x) : Block (y, x) {};
	/**
	 * Default destructor
	 */
	~Solid () override = default;
	/**
	 * Solid block doesn't change its state
	 */
	void stateChange(bool canFall) override {};

private:
};

#endif //TERMWORK_SOLID_H