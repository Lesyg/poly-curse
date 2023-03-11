#ifndef TERMWORK_GAME_H
#define TERMWORK_GAME_H

#include "Window.h"
#include "File.h"

class Game {
public:
	/**
	 * Basic constructor
	 */
	Game();
	/**
	 * Basic destructor that ends ncurses mode
	 */
	~Game();
	/**
	 * Method that handles user input
	 */
	void handleInput();
	/**
	 * Updates the window state
	 * If the terminal is resized it redraws it
	 * @param isResize information if the terminal was resized
	 */
	void updateState(bool isResize);
	/**
	 * Pauses the game and brings up a menu
	 */
	void pause();
	/**
	 * Getter for endGame
	 * @return endgame
	 */
	bool isOver() const;
	/**
	 * Creates a player on the top side of the map
	 */
	void createPlayer();
	/**
	 * Makes the game raedy for another map
	 */
	void end();
	void displayScore();
private:
	void newGame();
	void loadGame (File &saveFile, Menu &menu);
	std::vector<std::shared_ptr<Character>> characters;
	bool endGame;
	Window * window = new Window();
	Map map;
	int score = 0;
};

#endif //TERMWORK_GAME_H
