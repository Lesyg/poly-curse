#ifndef TERMWORK_MENU_H
#define TERMWORK_MENU_H

#include "Window.h"
#include <filesystem>
#include <vector>

class Menu {
public:
	/**
	 * Basic constructor
	 */
	Menu() = default;
	/**
	 * Default destructor
	 */
	~Menu() = default;
	/**
	 * Opens the menu and allows user to navigate
	 * @return returns selected menu option
	 */
	int openMenu();
	/**
	 * Displays an error message and forces the user to press enter
	 * @param height window height
	 * @param width window width
	 */
	void displayError (int height, int width);
	/**
	 * Navigates the manu window
	 * @return
	 */
	int navigateMenu (WINDOW * window, int numOfFiles, int *select);
	/**
	 * Validates a file name
	 * file name can contain only characters a-Z
	 * @param file to be validated
	 * @return returns true if file name contains only letters
	 */
	bool validateFile (const std::string & file);
	/**
	 * Creates a menu window
	 * @param height
	 * @param width
	 * @return returns a new menu window
	 */
	WINDOW * createWindow (int height, int width);

private:
	std::vector<std::string> menu = {{"new game"}, {"load game"}, {"quit game"}, {"resume game"}, {"save game"}};
};

#endif //TERMWORK_MENU_H