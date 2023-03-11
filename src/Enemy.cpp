#include "Enemy.h"

void Enemy::findPlayer (const Window &window, int * corY, int * corX) {
	int yMax = window.getHeight();
	int xMax = window.getWidth();
	for (int i = yMax; i > 0; --i) {
		for (int j = xMax; j > 0; --j) {
			if (window.getColorAt(i, j) == COLOR_PAIR(PLAYER)) {
				*corY = i;
				*corX = j;
				return;
			}
		}
	}
	*corY = yMax/2;
	*corX = xMax/2;
}