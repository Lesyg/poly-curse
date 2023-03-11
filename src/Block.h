#ifndef TERMWORK_BLOCK_H
#define TERMWORK_BLOCK_H

#include "Window.h"

class Block {
public:
	/**
	 * Basic constructor for Block class
	 * Initializes block coordinates
	 * @param y coordinate Y
	 * @param x coordinate X
	 */
	Block(int y, int x) : corY(y), corX(x) {};
	/**
	 * Virtual Block destructor
	 */
	virtual ~Block() = default;
	/**
	 *	Overloaded equality operator
	 *	Compares coordinates of 2 Block objects
	 * @param block
	 * @return returns true if both coordinates are the same
	 */
	bool operator== (const Block &block) const;
	/**
	 * Writes information about the block into a output stream
	 * using a virtual print method
	 * @param output takes ostream as input
	 * @param block const reference to an object
	 * @return return inputted output stream
	 */
	friend std::ostream& operator << (std::ostream & output, Block &block);
	/**
	 * Prints the actual block information
	 * is needed because of << operator limitations
	 * @param output takes ostream as input
	 */
	virtual void print(std::ostream & output) const = 0;
	/**
	 *e Draws the block in the correct coordinates
	 * using the correct color
	 * @param window takes window object to which the block will be drawn
	 */
	virtual void draw (const Window &window ) const = 0;
	/**
	 * Draws an empty space at the block location
	 * @param window where the block will be drawn to
	 */
	void unDraw (const Window &window) const;
	/**
	 * Getter for corX
	 * @return returns x coordinate
	 */
	int getCorX () const;
	/**
	 * Getter for corY
	 * @return returns y coordinate
	 */
	int getCorY () const;
	/**
	 * Removes the item from inventory
	 * @return returns the item that is removed
	 */
	virtual std::string type() const = 0;
	/**
	 * Moves the block 1 block down
	 * @param canFall controls whether or not the block can fall
	 */
	virtual void stateChange (bool canFall) = 0;

protected:
	int corY;
	int corX;

private:
};

#endif //TERMWORK_BLOCK_H