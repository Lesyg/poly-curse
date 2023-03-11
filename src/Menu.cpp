#include "Menu.h"

WINDOW * Menu::createWindow (int height, int width) {
	int xMax, yMax;
	getmaxyx(stdscr, yMax, xMax);
	if (yMax < 10 || xMax < 30) {
		throw std::out_of_range ("the terminal is to small");
	}
	WINDOW * menuWindow = newwin(height, width, (yMax - height)/2, (xMax - width)/2);
	keypad (menuWindow, true);
	box (menuWindow, 0, 0);
	return menuWindow;
}

int Menu::openMenu () {
	WINDOW * menuWindow = createWindow (12, 30);
	mvwaddstr(menuWindow, 1, 1, " Welcome to a sandbox game");
	int select = 0;
	while (true) {
		for (auto i = 0; i < (int)menu.size(); ++i) {
			if (i == select) {
				wattron(menuWindow, A_REVERSE);
				mvwaddstr(menuWindow, i + 3, 1, menu[i].c_str ());
				wattroff(menuWindow, A_REVERSE);
			} else {
				mvwaddstr(menuWindow, i + 3, 1, menu[i].c_str ());
			}
		}
		wrefresh (menuWindow);
		if (navigateMenu (menuWindow, menu.size () - 1, &select) == -2) {
			delwin (menuWindow);
			return select;
		}
	}
}

int Menu::navigateMenu (WINDOW * window, int numOfFiles, int *select) {
	int input = wgetch (window);
	switch (input) {
		case KEY_UP:
			if (*select != 0) {
				(*select)--;
			} else {
				(*select) = numOfFiles;
			}
			return *select;
		case KEY_DOWN:
			if(*select != numOfFiles) {
				(*select)++;
			} else {
				(*select) = 0;
			}
			return  *select;
		case '\n':
			return -2;
		default:
			break;
	}
	return ERR;
}

void Menu::displayError (int height, int width) {
	WINDOW *errorWindow = createWindow (5, 20);
	mvwaddstr(errorWindow, 1, 2, "please increase");
	mvwaddstr(errorWindow, 2, 3, "the terminal");
	mvwaddstr(errorWindow, 3, 7, "size");
	while (true) {
		int input = wgetch (errorWindow);
		if (input == KEY_RESIZE) {
			wbkgd (stdscr, COLOR_PAIR(BACKGROUND));
			int x, y;
			getmaxyx(stdscr, y, x);
			refresh ();
			wrefresh (errorWindow);
			if (height < y && width < x) {
				delwin (errorWindow);
				return;
			}
		}
	}
}

bool Menu::validateFile (const std::string &file) {
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