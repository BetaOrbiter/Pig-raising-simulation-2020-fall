#include "Factory.h"
#include "Pigs.h"
#include <algorithm>
/* Old version code
inline farm::SizeType farm::Factory::pigNum(void) const
{
	return kindIndex[0].;
}

inline farm::SizeType Factory::pigNum(farm::Color k) const
{
	return kindInfo[k].totalNum;
}

inline farm::SizeType Factory::pigNum(farm::SizeType penNum) const
{
	return penInfo[penNum].totalNum;
}

bool Factory::purChase(ptrToPig& victim)
{
	if (victim->cost() > money)
		return false;
	if (false == distribute(victim))
		return false;

	money -= victim->cost();

	const auto kind = victim->getColor();
	kindIndex[kind].push_back(victim);
	kindInfo[kind].totalNum++;
	kindInfo[kind].totalWeight += victim->getWeight();
	kindInfo[kind].totalValue += victim->getValue();

	const auto penNum = victim->penNum;
	penInfo[penNum].totalNum++;
	penInfo[penNum].totalWeight += victim->getWeight();
	penInfo[penNum].totalValue += victim->getValue();

	return true;
}

void Factory::sellOut(void)
{
	for (farm::SizeType pos = 0; pos < pens.size(); pos++)
		sell(pos);
}

void Factory::sell(farm::SizeType penNum)
{
	auto& pen = pens[penNum];
	auto newEnd = std::remove_if(pen.begin(), pen.end(), [](ptrToPig& p) {return p->isMature(); });
	Pigs toBeSold(newEnd, pen.end());
//	std::for_each(toBeSold.begin(), toBeSold.end(), static_cast<void (Factory::*)(ptrToPig&)> (&Factory::sell));
}

void Factory::sell(farm::Color k)
{
	auto& color = kindIndex[k];
	auto newEnd = std::remove_if(color.begin(), color.end(), [](ptrToPig &p) {return p->isMature(); });
	Pigs toBeSold(newEnd, color.end());
//	std::for_each(toBeSold.begin(), toBeSold.end(), static_cast<void (Factory::*)(ptrToPig&)> (&Factory::sell));

}

void Factory::sell(ptrToPig& p)
{
	const farm::SizeType penNum = p->penNum;
	const farm::MoneyType value = p->getValue();
	const farm::WeightType weight = p->getWeight();

	auto& pen = pens[penNum];
	pen.erase(find(pen.begin(), pen.end(), p));
	penInfo[penNum].totalNum--;
	penInfo[penNum].totalValue -= value;
	penInfo[penNum].totalWeight -= weight;

	auto& col = kindIndex[p->color];
	col.erase(find(col.begin(), col.end(), p));
	kindInfo[p->color].totalNum--;
	kindInfo[p->color].totalValue -= value;
	kindInfo[p->color].totalWeight -= weight;

	money += value;
}

std::ostream& operator<<(std::ostream& os, const Pigs& ps)
{
	std::cout << "We have " << ps.size() << " Pigs int this set." << std::endl;
	for (const auto& pig : ps)
		std::cout << *pig << std::endl;
	return std::cout;
}

std::ostream& operator<<(std::ostream& os, const Factory& fa)
{
	std::cout << "We have " << fa.pigNum() << " in this factory" << std::endl;
	for (Factory::SizeType pos=0; pos<100; pos++)
		if (!fa.pens[pos].empty())
			std::cout << "In pen:" << pos << std::endl << fa.pens[pos] << std::endl;
	return std::cout;
}

void Factory::step(void)
{
	for (auto& color : kindIndex)
		for (auto& pig : color) {
			MoneyType dValue = pig->getValue();
			BasicPig::WeightType dWei = pig->gainWeight();
			dValue -= pig->getValue();
			kindInfo[pig->color].totalWeight += dWei;
			kindInfo[pig->color].totalValue += dValue;
			penInfo[pig->color].totalWeight += dWei;
			penInfo[pig->color].totalValue += dValue;
		}
}

bool Factory::distribute(ptrToPig& p)
{
	farm::SizeType pos;
	std::vector<farm::SizeType> ablePos;
	
	for (pos = 0; pos < pens.size(); pos++) {
		if (pens[pos].empty()) {
			ablePos.push_back(pos);
			continue;
		}
		if ((farm::black == p->color && farm::black == pens[pos][0]->color) ||
			(farm::black == p->color && farm::black == pens[pos][0]->color))
			ablePos.push_back(pos);
	}
	
	if (ablePos.empty())
		return false;

	pos = ablePos[rand() % ablePos.size()];
	p->penNum = pos;
	pens[pos].push_back(p);
	return true;
}
*/