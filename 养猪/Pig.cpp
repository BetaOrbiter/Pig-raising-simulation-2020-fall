#include "Factory.h"
#include <cstdlib>
extern Time t;
Pigs generate(Factory::SizeType num) {
	Pigs pigs(num);
	for (auto& pig : pigs)
		pig = std::make_shared<PigNode>(t,static_cast<BasicPig::Color>(rand() % 3), rand() % 40 + 100);
	return pigs;
}