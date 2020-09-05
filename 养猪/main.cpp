#include "Factory.h"
#include <iostream>
#include <fstream>
#include<vector>
#include <string>
#include<memory>
int main(void) {
	Factory fa;
	Pigs toBesold = generate(8);

	fa.step();
	return 0;
}