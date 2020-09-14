#include "Factory.h"
#include "Pigs.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
int main(void) {
	farm::Factory fa("save.txt","rec.txt",farm::Factory::old);
	//std::fstream aa("save.txt", std::ios::in | std::ios::out);
	//aa << "skljdflsdf";
	
	constexpr int choice = 0;
	do {
		farm::Pigs pigs(10);
		//std::cout << pigs;
		fa.purChase(pigs[rand()%10]);
		
		fa.step();
		fa.sellOut();
	} while (fa.getDay()<30000);

	fa.save();
	
	return 0;
}