#include "Map.h"

Map::Map () {
	getmaxyx(stdscr, height, width);
}

void Map::generateMap (WINDOW * window) {
	getmaxyx(window, height, width);
	for (int i = 1; i < height-1; ++i) {
		for (int j = 1; j < width-1; ++j) {
			//Creates a wave like terrain
			if( i > (2*(sin(double(0.1*j-3))* cos (double(0.5*j-4)))+height/3)) {
				if( (randomInt (0, 100) > RAND_SPACE/i)) {
					if (randomInt (0, 100) > (i*j % RAND_LIQUID)) {
						if (randomInt (0, 100) > (i*j % RAND_SOLID)) {
							mapOfBlocks.push_back (std::make_shared<Stone> (i, j));
						} else {
							mapOfBlocks.push_back (std::make_shared<Dirt> (i, j));
						}
					} else {
						if (randomInt (0, 100) > (i*j % RAND_SOLID)) {
							mapOfBlocks.push_back (std::make_shared<Water> (i, j));
						} else {
							mapOfBlocks.push_back (std::make_shared<Lava> (i, j));
						}
					}
				}
			}
		}
	}
}

void Map::draw (const Window &window) const {
	for (const auto& it : mapOfBlocks) {
		it->draw (window);
	}
	for (const auto& it : mapOfBlocks) {
		it->unDraw (window);
		it->stateChange((window.getColorAt (it->getCorY()+1, it->getCorX()) == COLOR_PAIR(WINDOW_BG)) && !(randomInt (0, 4)));
		it->draw (window);
	}
}

std::string Map::destroyBlock (int y, int x, Window &window) {
	std::vector<std::shared_ptr<Block>>::iterator it;
	for (it = mapOfBlocks.begin(); it != mapOfBlocks.end(); ++it) {
		if ((*it)->getCorY() == y && (*it)->getCorX() == x) {
			std::string item = (*it)->type();
			(*it)->unDraw (window);
			mapOfBlocks.erase (it);
			return item;
		}
	}
	return " ";
}

void Map::destroyBlock () {
	mapOfBlocks.clear();
}

void Map::saveToFile (std::ostream &output) {
	for (const auto& it : mapOfBlocks) {
		output << *it << std::endl;
	}
}

void Map::createBlock (const std::string& block, int y, int x) {
	if (block == STONE_CH) {
		mapOfBlocks.push_back (std::make_shared<Stone>(y, x));
		return;
	}
	if (block == DIRT_CH) {
		mapOfBlocks.push_back (std::make_shared<Dirt>(y, x));
		return;
	}
	if (block == WATER_CH) {
		mapOfBlocks.push_back (std::make_shared<Water>(y, x));
		return;
	}
	if (block == LAVA_CH) {
		mapOfBlocks.push_back (std::make_shared<Lava>(y, x));
		return;
	}
	throw std::invalid_argument ("invalid block type");
}