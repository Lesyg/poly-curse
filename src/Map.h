#ifndef TERMWORK_MAP_H
#define TERMWORK_MAP_H

#include <vector>
#include <memory>
#include "Water.h"
#include "Stone.h"
#include "Dirt.h"
#include "Lava.h"
#include <cmath>
#include <random>
#include <fstream>

class Map {
public:
	/**
	 * Basic constructor that initializes the height and width of the map
	 * according to the terminal size
	 */
	Map ();
	/**
	 * Default destructor
	 */
	~Map () = default;
	/**
	 * Generates a vector of Block
	 * The map is filled with Block with 80 / 20 ratio of solids to liquids
	 * It also uses some goniometric functions to generate a less monotone terrain
	 * It would be interesting to add some more advanced procedural generation using perlin
	 * noise, but it would toke some time to correctly implement
	 * @param window on which the map takes place
	 */
	void generateMap(WINDOW * window);
	/**
	 * Draws the map to the window
	 * @param window where the map will be drawn
	 */
	void draw(const Window &window) const;
	/**
	 * Destroys the block at the inputted coordinates
	 * @param y coordinate Y
	 * @param x coordinate X
	 * @param window where the map takes place
	 * @return string representing block that was destroyed
	 */
	std::string destroyBlock(int y, int x, Window &window);
	/**
	 * Destroys the whole map
	 */
	void destroyBlock();
	/**
	 * Saves the information about the map to a file
	 * @param output stream to which the information is written
	 */
	void saveToFile (std::ostream &output);
	/**
	 * Creates a block of specified type at inputted coordinates
	 * @param block type of block
	 * @param y coordinate Y
	 * @param x coordinate X
	 */
	void createBlock(const std::string& block, int y, int x);
	/**
	 * Loads the map from a file
	 * @param file
	 */
	void loadFromFile (const std::string& file) {};


private:
	std::vector<std::shared_ptr<Block>> mapOfBlocks;
	int width;
	int height;
};

#endif //TERMWORK_MAP_H