#ifndef TERMWORK_FILE_H
#define TERMWORK_FILE_H

//#include "Window.h"
#include "Menu.h"
#include "Player.h"
#include "Ranged.h"
#include "Meele.h"
#include "Map.h"
#include <filesystem>

class File {
public:
	/**
	 * Default constructor
	 */
	File () = default;
	/**
	 * Default destructor
	 */
	~File() = default;
	/**
	 * Ask the user for a name of the file that is being saved
	 * @return returns the new file name
	 */
	std::string fileName();
	/**
	 * Displays a menu of all the file in maps folder
	 * @return returns the name of the selected file
	 */
	std::string displayFiles ();
	/**
	 * Saves the current map into a file
	 * @param map map of block to be saved
	 * @param file to which the information is saved
	 * @param height of the map window
	 * @param width of the map window
	 * @param characters all of the characters on the map
	 */
	void saveToFile (Map &map,const std::string& file, int height, int width, std::vector<std::shared_ptr<Character>> &characters );
	/**
	 * Loads the map from a file
	 * @param file from which the map is loaded
	 * @param map of block that will be created
	 * @param window where the game takes place
	 * @param characters that will be loaded
	 */
	void loadFromFile (const std::string& file, Map &map, Window &window, std::vector<std::shared_ptr<Character>> &characters);

private:
	/**
	 * Validates that the file name contains only letters a-Z
	 * @param file name to be validated
	 * @return true if file name is valid
	 */
	bool validateFile (const std::string &file);
};

#endif //TERMWORK_FILE_H