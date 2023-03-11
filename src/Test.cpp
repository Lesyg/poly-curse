#include "Menu.h"
#include "File.h"
#include <cassert>

class Test {
public:
	Test () = default;
	~Test() = default;

	void test () {
		Menu menu;
		assert(!menu.validateFile(""));
		assert(menu.validateFile("a"));
		assert(menu.validateFile("basicName"));
		assert(!menu.validateFile("not_basic_name"));
		assert(!menu.validateFile("conta1nsnumb3rs"));
		assert(!menu.validateFile("rnd12950'/';]"));
		assert(!menu.validateFile("\\/y\\e\\s"));
		assert(menu.validateFile(std::string("boringNameloooooooonsdfasdfsafgName")));
			std::cout << "validation succesfull" << std::endl;

		initscr();
		File file;
		Map map;
		Window window;
		std::vector<std::shared_ptr<Character>> characters;
		try {
			file.loadFromFile ("examples/maps/testCorrupt", map, window, characters);
			file.loadFromFile ("examples/maps/badFile", map, window, characters);
		} catch (...) {
			endwin();
			std::cout << "file corrupted" << std::endl;
		}
		endwin();
		std::cout << "all test completed" << std::endl;
	};
};