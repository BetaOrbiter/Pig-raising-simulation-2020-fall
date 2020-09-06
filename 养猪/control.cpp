#include "Factory.h"
#include "Pigs.h"
#include <iostream>
Time t = 0;
int main(void) {
	farm::Pigs ps(0, 10);
	std::cout << ps;
	return 0;
}