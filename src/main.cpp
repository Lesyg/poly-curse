#include "Test.cpp"
#include "Game.h"

#define TEST 0

int main () {
#if TEST == 0
	Game game;
	game.pause();

	while (! game.isOver()) {
		game.handleInput();
		game.updateState(false);
		if(game.isOver()) {
			game.end();
			game.pause();
		}
	}
#endif

#if TEST == 1
	Test test;
	test.test();
#endif

    return 0;
}