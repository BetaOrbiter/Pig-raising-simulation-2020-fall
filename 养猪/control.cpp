#include "Factory.h"
#include "Pigs.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
int main(void) {
	farm::Factory fa(2000000000);
	constexpr int choice = 0;
	do {
		farm::Pigs pigs(10);
		//std::cout << pigs;
		fa.purChase(pigs[rand()%10]);
		
		fa.step();
		fa.sellOut();
	} while (fa.getMoney()>1000);

	std::cout << fa;
	return 0;
}