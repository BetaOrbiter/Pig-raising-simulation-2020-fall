#include "Pigs.h"
#include <iostream>
farm::Pigs::Pigs(Time t, SizeType num):totalWeight(0), totalValue(0)
{
	std::vector<ptrToPig> index;
	index.reserve(num);
	for (size_t i = 0; i < num; ++i) {
		ptrToPig ptr = std::make_shared<BasicPig>(t);
		index.push_back(ptr);
		totalWeight += ptr->gainWeight();
		totalValue += ptr->getValue();
	}
}

farm::Pigs& farm::Pigs::add(ptrToPig& ptr)
{
	totalValue += ptr->getValue();
	totalWeight += ptr->getWeight();
	illNum += !ptr->isHealthy();
	Index.push_back(ptr);
}

farm::Pigs& farm::Pigs::erase(const farm::SizeType pos)
{
	const auto ptrToPtr = Index.begin() + pos;
	totalValue -= (*ptrToPtr)->getValue();
	totalWeight -= (*ptrToPtr)->getWeight();
	illNum -= !(*ptrToPtr)->isHealthy();
	Index.erase(ptrToPtr);
	return *this;
}

farm::Pigs& farm::Pigs::erase(const ptrToPig& ptr)
{
	const auto ptrToPtr = std::find(Index.begin(), Index.end(), ptr);
	if (ptrToPtr != Index.end()) {
		totalValue -= (*ptrToPtr)->getValue();
		totalWeight -= (*ptrToPtr)->getWeight();
		illNum -= !(*ptrToPtr)->isHealthy();
		Index.erase(ptrToPtr);
	}
	return *this;
}

std::istream& farm::operator>>(std::istream& is, Pigs& ps)
{
	int size;
	is >> size >> ps.totalWeight >> ps.illNum;
	ps.Index.resize(size);
	for (auto& pig : ps.Index)
		is >> *pig;
	return is;
}

std::ostream& farm::operator<<(std::ostream& os, const Pigs& ps)
{
	os << "We have " << ps.Index.size() << " pigs in this set." << std::endl;
	os << "Its total weight is " << ps.totalWeight << " catty." << std::endl;
	os << ps.illNum << "ill Pig in this set." << std::endl;
	for (const auto pig : ps.Index)
		os << *pig << std::endl;
	return os;
}
