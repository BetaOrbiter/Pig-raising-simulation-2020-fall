#include "Factory.h"
#include <iostream>
#include <fstream>
#include<vector>
int main(void) {
	std::ifstream saving;
	Factory fa(saving);
	Time t = 0;
	for (t = 0; 0 != fa.getMoney(); t++) {

	}
	return 0;
}