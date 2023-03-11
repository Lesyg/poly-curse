#include "Game.h"

Game::Game () {
	endGame = true;
}

Game::~Game () {
	delete window;
	endwin();
}

//TODO handle ctr+d and check for invalid input
void Game::handleInput () {
	chtype  key = window->getInput();
	if (key == (unsigned)ERR) {
		return;
	}
	switch (key) {
		case 'p':
			pause();
			break;
		case KEY_RESIZE:
			updateState (true);
		case CTRL_D:
			endGame = true;
			return;
		default:
			auto it = characters.begin();
			while ( it != characters.end()) {
				(*it)->move(*window, key, characters);
				if(characters.empty()) {
					endGame = true;
					Menu endScreen;
					WINDOW * endWindow = endScreen.createWindow (4,25);
					mvwaddstr(endWindow, 1, 6, "Oops you died");
					mvwaddstr(endWindow, 2, 8, std::string("score: " + std::to_string (score)).c_str());
					while (wgetch (endWindow) != '\n');
					return;
				}
				if ((*it)->getHealthPoints() <=0) {
					(*it)->clean (*window);
					it = characters.erase (it);
					score++;
					continue;
				}
				if ((*it)->getMine()) {
					(*it)->addToInv(map.destroyBlock ((*it)->getDirY(), (*it)->getDirX(), *window));
					map.draw (*window);
				} else if ((*it)->getPlace()) {
//					if ((*it)->canMove ((*it)->getDirY(), (*it)->getDirX(), *window)) {
					try {
						map.createBlock ((*it)->popFromInv(), (*it)->getDirY(), (*it)->getDirX());
					} catch (...) {}
						map.draw (*window);
//					}
				}
				++it;
			}
	}
}

void Game::updateState (bool isResize) {
	if (isResize) {
		int xMax, yMax;
		getmaxyx(stdscr, yMax, xMax);
		if (yMax < window->getHeight() || xMax < window->getWidth()) {
			Menu error;
			try {
				error.displayError (window->getHeight(), window->getWidth());
			} catch (std::out_of_range &range) {
				endGame = true;
				return;
			}

		}
		window->redraw();
	}
	if (!endGame && characters.size() < MAX_ENEMIES) {
		if (randomInt (0, 1)) {
			characters.push_back (std::make_shared<Ranged>(window->getHeight()/3-2, (randomInt (1, window->getWidth())-2), 5, RANGED_HP));
		} else {
			characters.push_back (std::make_shared<Meele>(window->getHeight()/3-2,(randomInt (1, window->getWidth())-2), 5, MEELE_HP));
		}
	}
	map.draw (*window);
	displayScore();
	window->refresh();
}

void Game::displayScore() {
	window->addAt (0, 21, std::string("score: " + std::to_string(score) + " "));
}

bool Game::isOver () const {
	return endGame;
}

void Game::pause () {
	Menu menu;
	File saveFile;
	int tmp;
	try {
		tmp = menu.openMenu();
	} catch (std::out_of_range &range) {
		endGame = true;
		return;
	}
	switch (tmp) {
		case QUIT:
//			score = 0;
			endGame = true;
			return;
		case LOAD:
			window->redraw();
			loadGame(saveFile, menu);
			return;
		case NEW:
			newGame();
			return;
		case RESUME:
			window->redraw();
			map.draw(*window);
			for(const auto& it : characters) {
				it->draw (*window);
			}
			return;
		case SAVE:
			if (endGame) {
				return;
			}
			saveFile.saveToFile(map, "examples/maps/" + saveFile.fileName(), window->getHeight(), window->getWidth(), characters);
			endGame = true;
			return;
		default:
			return;
	}
}

void Game::createPlayer () {
	characters.push_back (std::make_shared<Player>(window->getHeight()/3,window->getWidth()/4 ,5, PLAYER_HP));
}

void Game::end () {
	score = 0;
	map.destroyBlock();
	characters.clear();
	wclear (stdscr);
	wrefresh (stdscr);
	delete window;
	window = new Window();
}

void Game::newGame () {
	if (!endGame) {
		window->redraw();
		map.draw(*window);
		for(const auto& it : characters) {
			it->draw (*window);
		}
		return;
	}
	try {
		window->createGameWindow();
	} catch (std::out_of_range &range) {
		return;
	}
	map.generateMap (window->getWindow());
	map.draw(*window);
	createPlayer();
	for(const auto& it : characters) {
		it->draw (*window);
	}
	endGame = false;
}

void Game::loadGame (File &saveFile, Menu &menu) {
	end();
	std::string file;
	file = saveFile.displayFiles();
	try {
		saveFile.loadFromFile ("examples/maps/" + file, map, *window, characters);
	} catch (std::invalid_argument &error) {
		endGame = true;
		return;
	} catch (std::out_of_range &tmp) {
		int y, x;
		std::ifstream fp;
		fp.open ("examples/maps/" + file);
		fp >> y >> x;
		try {
			menu.displayError(y, x);
		} catch (std::out_of_range &range) {
			endGame = true;
			fp.close();
			return;
		}
		fp.close();
		saveFile.loadFromFile ("examples/maps/" + file, map, *window, characters);
	}
	updateState (false);
	endGame = false;
}