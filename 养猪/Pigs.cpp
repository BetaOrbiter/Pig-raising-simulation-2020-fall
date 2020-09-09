#include "Pigs.h"
#include <iostream>
farm::Pigs::Pigs(SizeType num):totalWeight(0), totalValue(0)
{
	for (size_t i = 0; i < num; ++i) {
		ptrToPig ptr = std::make_shared<BasicPig>();
		Index.push_back(ptr);
		totalWeight += ptr->getWeight();
		totalValue += ptr->getValue();
	}
}

farm::Pigs::iterator farm::Pigs::erase(iterator beg, iterator end)
{
	for (auto iter = beg; iter != end; iter++) {
		totalValue -= (*iter)->getValue();
		totalWeight -= (*iter)->getWeight();
		illNum -= !(*iter)->isHealthy();
	}
	return Index.erase(beg, end);
}

farm::Pigs::iterator farm::Pigs::erase(iterator target)
{
	totalValue -= (*target)->getValue();
	totalWeight -= (*target)->getWeight();
	illNum -= !(*target)->isHealthy();
	return Index.erase(target);
}

farm::Pigs& farm::Pigs::add(ptrToPig& ptr)
{
	totalValue += ptr->getValue();
	totalWeight += ptr->getWeight();
	illNum += !ptr->isHealthy();
	Index.push_back(ptr);
	return *this;
}

void farm::Pigs::clear(void)
{
	totalValue = 0;
	totalWeight = 0;
	illNum = 0;
	Index.clear();
}

farm::Pigs::iterator farm::Pigs::erase(const farm::SizeType pos)
{
	auto ptrToPtr = Index.begin() + pos;
	if (ptrToPtr != Index.end()) {
		totalValue -= (*ptrToPtr)->getValue();
		totalWeight -= (*ptrToPtr)->getWeight();
		illNum -= !(*ptrToPtr)->isHealthy();
		ptrToPtr = Index.erase(ptrToPtr);
	}
	return ptrToPtr;
}

farm::Pigs::iterator farm::Pigs::erase(const ptrToPig& ptr)
{
	auto ptrToPtr = std::find(Index.begin(), Index.end(), ptr);
	if (ptrToPtr != Index.end()) {
		totalValue -= (*ptrToPtr)->getValue();
		totalWeight -= (*ptrToPtr)->getWeight();
		illNum -= !(*ptrToPtr)->isHealthy();
		ptrToPtr = Index.erase(ptrToPtr);
	}
	return ptrToPtr;
}

std::istream& farm::operator>>(std::istream& is, farm::Pigs& ps)
{
	farm::SizeType size;
	is >> size >> ps.illNum >> ps.totalWeight;
	ps.Index.resize(0);
	for (farm::SizeType i = 0; i < size; i++)
		ps.Index.push_back(std::make_shared<BasicPig>(is));
	return is;
}

std::ostream& farm::operator<<(std::ostream& os, const farm::Pigs& ps)
{
	os << /*"We have  <<*/ ps.Index.size() << /*" pigs in this set with "*/" " << ps.illNum << ' ';// << /*" ill pig."*/ << std::endl;
	os << /*"Its total weight is  <<*/ ps.totalWeight << /*" catty."*/" " << std::endl;
	for (const auto pig : ps.Index)
		os << *pig << std::endl;
	return os;
}
