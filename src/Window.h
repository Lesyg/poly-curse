#ifndef TERMWORK_WINDOW_H
#define TERMWORK_WINDOW_H

#include "Constants.h"
#include <ncurses.h>
#include <string>
#include <stdexcept>
#include <iostream>

class Window {
public:
	/**
	 * Constructor initializes ncurses mode, colors
	 * sets the basic parameters no echo and no cursor
	 * sets the height and width as the resolution of the terminal
	 */
	Window();
	/**
	 * Destroys the window and ends ncurses mode
	 */
	~Window();
	/**
	 * Adds a border to the window within the terminal
	 */
	void addBorder();
	/**
	 * Refreshes the window
	 */
	void refresh() const;
	/**
	 * Adds a string to the window at the specified coordinates
	 * @param y coordinate Y
	 * @param x coordinate X
	 * @param output outputted string
	 */
	void addAt(int y, int x, const std::string &output) const;
	/**
	 * Adds a single char to the window at the specified coordinates
	 * @param y coordinate Y
	 * @param x coordinate X
	 * @param output outputted char
	 */
	void addAt(int y, int x, chtype output) const;
	/**
	 * Requests input from user
	 * @return returns ncurses type chtype
	 */
	chtype getInput() const;
	/**
	 * Redraws the window
	 */
	void redraw();
	/**
	 * Getter for the window
	 * @return returns the window where the game takes place
	 */
	WINDOW * getWindow () const;
	/**
	 * Getter for window width
	 * @return returns window width
	 */
	int getWidth () const;
	/**
	 * Getter for window height
	 * @return returns window height
	 */
	int getHeight () const;
	/**
	 * Gets the char at the specified coordinates
	 * @param y coordinate Y
	 * @param x coordinate X
	 * @return returns a char
	 */
	chtype getCharAt(int y, int x) const;
	/**
	 * Gets the color at the specified coordinates
	 * @param y coordinate Y
	 * @param x coordinate X
	 * @return returns the ncurses color type
	 */
	chtype getColorAt(int y, int x) const;
	/**
	 * Creates the game window
	 */
	void createGameWindow();
	/**
	 * Loads the window for a new map loaded from a file
	 * @param minHeight minimal Height that is needed to play this map
	 * @param minWidth minimal width that is needed to play this map
	 */
	void loadWindow(int minHeight, int minWidth);
private:
	/**
	 * Constructs the window for the game
	 * @param height of the new window
	 * @param width width of the new window
	 */
	void construct (int height, int width);
	WINDOW * boardWindow;
	int height;
	int width;
};

#endif //TERMWORK_WINDOW_H