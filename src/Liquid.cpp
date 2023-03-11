#include "Liquid.h"

void Liquid::stateChange (bool canFall) {
	if (!canFall) {
		return;
	}
	corY++;
}