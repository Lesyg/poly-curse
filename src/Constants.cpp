#include "Constants.h"

void initializeColors() {
	if (!has_colors()) {
		throw std::runtime_error("terminal doesnt support colors");
	}
	if (!can_change_color()) {
		throw std::runtime_error("terminal doesnt color change");
	}

	start_color();
	init_color (BROWN, 350, 200, 75);
	init_color (GREY, 300, 300, 300);
	init_color (LIGHT_BLUE, 450, 750, 750);
	init_color (WHITE, 1000, 1000, 1000);
	init_color (RED, 900, 100, 100);
	init_color (YELLOW, 800, 1000, 100);
	init_color (ORANGE, 900, 300, 50);
	init_color (GREEN, 100, 1000, 100);
	init_color (BLUE, 40, 200, 800);

	init_pair(BACKGROUND, WHITE, WHITE);
	init_pair(WINDOW_BG, WHITE, LIGHT_BLUE);
	init_pair(STONE, COLOR_BLACK, GREY);
	init_pair (DIRT, COLOR_WHITE, BROWN);
	init_pair(IRON, COLOR_WHITE, COLOR_BLACK);
	init_pair(PLAYER, COLOR_BLACK, GREEN);
	init_pair(RANGED, WHITE, RED);
	init_pair(MEELE, COLOR_BLACK, RED);

	init_pair (WATER, COLOR_WHITE, BLUE);
	init_pair (LAVA, COLOR_WHITE, ORANGE);
}

int randomInt (int low, int high) {
	std::random_device rand;
	std::mt19937 gen(rand());
	std::uniform_int_distribution<int> dist(low, high);
	return dist(gen);
}