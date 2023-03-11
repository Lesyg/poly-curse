#include "Window.h"

Window::Window() {
	boardWindow = nullptr;
	initscr();
	try {
		initializeColors();
	} catch (std::runtime_error &error) {
	}
	bkgd(COLOR_PAIR (BACKGROUND));
	wrefresh(stdscr);
	noecho();
	curs_set (0);
}

Window::~Window() {
	delwin (boardWindow);
}

void Window::addBorder () {
	wattron(boardWindow, COLOR_PAIR (BACKGROUND));
	box(boardWindow, 0, 0);
	wattroff(boardWindow, COLOR_PAIR (BACKGROUND));
}

void Window::refresh () const {
	wrefresh(boardWindow);
}

void Window::addAt (int y, int x, const std::string &ch) const {
	if (y > height || x > width || y < 0 || x < 0) {
		return;
	}
	mvwaddstr(boardWindow, y, x, ch.c_str ());
}

void Window::addAt (int y, int x, chtype ch) const {
	if (y > height || x > width || y < 0 || x < 0) {
		return;
	}
	mvwaddch(boardWindow, y, x, ch);
}

chtype Window::getInput () const {
	return wgetch(boardWindow);
}

void Window::construct (int h, int w) {
	int xMax, yMax;
	getmaxyx(stdscr, yMax, xMax);
	boardWindow = newwin (h, w, yMax/2 - h/2, xMax/2 - w/2);
	keypad (boardWindow, true);
	addBorder();
}

void Window::redraw () {
	wclear (stdscr);
	wresize (boardWindow, height, width);
	wbkgd (stdscr, COLOR_PAIR(BACKGROUND));
	wbkgd (boardWindow, COLOR_PAIR(WINDOW_BG));
	addBorder();
	wrefresh (stdscr);
}

WINDOW* Window::getWindow () const {
	return boardWindow;
}

int Window::getWidth () const {
	return width;
}

int Window::getHeight () const {
	return height;
}

void Window::createGameWindow () {
	getmaxyx(stdscr, height, width);
	if (height < 10 || width < 30) {
		throw std::out_of_range ("the terminal is to small");
	}
	construct (height / 1.1, width / 1.1);
	getmaxyx(boardWindow, height, width);
	wbkgd (boardWindow, COLOR_PAIR(WINDOW_BG));
	this->refresh();
}

void Window::loadWindow (int minHeight, int minWidth) {
	delwin (boardWindow);
	int xMax, yMax;
	getmaxyx(stdscr, yMax, xMax);
	if (yMax < minHeight || xMax < minWidth) {
		throw std::out_of_range  ("terminal window is too small for this map");
	}
	construct (minHeight, minWidth);
	height = minHeight;
	width = minWidth;
	wbkgd (boardWindow, COLOR_PAIR(WINDOW_BG));
	this->refresh();
}

chtype Window::getCharAt (int y, int x) const {
	return mvwinch(boardWindow, y, x) & A_CHARTEXT;
}

chtype Window::getColorAt (int y, int x) const {
	return mvwinch(boardWindow, y, x) & A_COLOR;
}