#include "File.h"

std::string File::fileName() {
	Menu menu;
	WINDOW *tmpWindow = menu.createWindow (5, 25);
	mvwaddstr(tmpWindow, 1, 6, "file name (a-Z)");
	echo();
	curs_set (1);
	char file[FILE_MAX_LENGHT] = "";
	while (!validateFile (std::string(file))) {
		mvwgetnstr(tmpWindow, 2, 1, file, FILE_MAX_LENGHT);
		wmove (tmpWindow,2, 1);
		wclrtobot (tmpWindow);
		box (tmpWindow, 0, 0);
	}
	delwin (tmpWindow);
	return std::string {file};
}

bool File::validateFile (const std::string &file) {
	if (file.length() < 1) {
		return false;
	}
	for (const auto &it : file) {
		if (!std::isalpha(it)) {
			return false;
		}
	}
	for (const auto &it : std::filesystem::directory_iterator("examples/maps")) {
		if (it.path().filename() == file) {
			return false;
		}
	}
	return true;
}

std::string File::displayFiles () {
	int numOfFiles = 0;
	for (auto it : std::filesystem::directory_iterator("examples/maps")) {
		numOfFiles++;
	}
	Menu menu;
	WINDOW *tmpWindow = menu.createWindow (numOfFiles+3, 30);
	mvwaddstr(tmpWindow, 1, 10, "Choose file");
	std::string returnFile;
	int select = 0;
	while(true) {
		int cnt = 0;
		for (const auto &it : std::filesystem::directory_iterator("examples/maps")) {
			if (cnt == select) {
				wattron(tmpWindow, A_REVERSE);
				mvwaddstr(tmpWindow, (cnt++)+2, 1, std::string(it.path().filename()).c_str());
				wattroff(tmpWindow, A_REVERSE);
				returnFile = std::string(it.path().filename());
			} else {
				mvwaddstr(tmpWindow, (cnt++)+2, 1, std::string(it.path().filename()).c_str());
			}
		}
		if (menu.navigateMenu(tmpWindow, numOfFiles-1, &select) == -2) {
			delwin (tmpWindow);
			return returnFile;
		}
	}
}


void File::saveToFile (Map &map,const std::string& file, int height, int width, std::vector<std::shared_ptr<Character>> &characters ) {
	std::ofstream tmp;
	tmp.open (file);
	tmp << height << " " << width << std::endl;
	tmp << "characters\n";
	for (const auto &it : characters) {
		tmp << *it << std::endl;
	}
	map.saveToFile(tmp);
	tmp.close();
}

//TODO clean up and check for correct input
void File::loadFromFile (const std::string& file, Map &map, Window &window, std::vector<std::shared_ptr<Character>> &characters) {
	std::ifstream tmp;
	tmp.open(file);
	if(!tmp.is_open()) {
		tmp.close();
		throw std::invalid_argument ("file is wrong");
	}
	std::string sY, sX, st, sHP, sDMG;
	std::getline (tmp, sY, ' ');
	std::getline (tmp, sX, '\n');
	try {
		window.loadWindow (std::stoi (sY), std::stoi (sX));
	} catch (std::out_of_range &error) {
		tmp.close();
		throw std::out_of_range(error.what());
	}
	std::getline (tmp, st, '\n');
	if (st != "characters") {
		tmp.close();
		throw std::invalid_argument ("corrupted file");
	}
	std::getline (tmp, st, ' ');
	while (st != "st" && st != "dt" && st != "wt" && st != "la") {
		std::getline (tmp, sY, ' ');
		std::getline (tmp, sX, ' ');
		std::getline (tmp, sHP, ' ');
		std::getline (tmp, sDMG, '\n');
		if (st == "pl") {
			characters.push_back (std::make_shared<Player>(std::stoi (sY), std::stoi (sX), std::stoi(sDMG), std::stoi(sHP)));
		} else if (st == "me") {
			characters.push_back (std::make_shared<Meele>(std::stoi (sY), std::stoi (sX), std::stoi(sDMG), std::stoi(sHP)));
		} else if (st == "ra") {
			characters.push_back (std::make_shared<Ranged>(std::stoi (sY), std::stoi (sX), std::stoi(sDMG), std::stoi(sHP)));
		} else {
			tmp.close();
			throw std::invalid_argument ("corrupted file");
		}
		std::getline (tmp, st, ' ');
	}
	while (! tmp.eof()) {
		std::getline (tmp, sY, ' ');
		std::getline (tmp, sX, '\n');
		try {
			map.createBlock (st, std::stoi (sY), std::stoi (sX));
		} catch (std::invalid_argument &error) {
			tmp.close();
			throw std::invalid_argument ("corrupted file");
		}
		std::getline (tmp, st, ' ');
	}
	tmp.close();
}