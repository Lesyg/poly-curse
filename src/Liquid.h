#ifndef TERMWORK_LIQUID_H
#define TERMWORK_LIQUID_H

#include "Block.h"

class Liquid : public Block{
public:
	/**
	 * Basic constructor
	 * @param y coordinate Y
	 * @param x coordinate X
	 */
	Liquid(int y, int x) : Block(y, x) {};
	/**
	 * Default destructor
	 */
	~Liquid() override = default;
	/**
	 * Change state
	 */
	void stateChange(bool canFall) override;

private:
};

#endif //TERMWORK_LIQUID_H