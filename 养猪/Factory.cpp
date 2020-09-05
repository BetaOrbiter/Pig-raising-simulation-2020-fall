#include "Factory.h"
#include <algorithm>

Time t;

inline Factory::SizeType Factory::pigNum(void)
{
	return kindInfo[0].totalNum + kindInfo[1].totalNum + kindInfo[2].totalNum;
}

inline Factory::SizeType Factory::pigNum(BasicPig::Color k)
{
	return kindInfo[k].totalNum;
}

inline Factory::SizeType Factory::pigNum(SizeType penNum)
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
	for (SizeType pos = 0; pos < pens.size(); pos++)
		sell(pos);
}

void Factory::sell(SizeType penNum)
{
	auto& pen = pens[penNum];
	auto newEnd = std::remove_if(pen.begin(), pen.end(), PigNode::isMature);
	Pigs toBeSold(newEnd, pen.end());
	std::for_each(toBeSold.begin(), toBeSold.end(), static_cast<void (Factory::*)(ptrToPig&)> (Factory::sell));
}

void Factory::sell(BasicPig::Color k)
{
	auto& color = kindIndex[k];
	auto newEnd = std::remove_if(color.begin(), color.end(), PigNode::isMature);
	Pigs toBeSold(newEnd, color.end());
	std::for_each(toBeSold.begin(), toBeSold.end(), static_cast<void (Factory::*)(ptrToPig&)> (Factory::sell));

}

void Factory::sell(ptrToPig& p)
{
	const SizeType penNum = p->penNum;
	const SizeType num = p->num;
	const MoneyType value = p->getValue();
	const PigNode::WeightType weight = p->getWeight();

	auto& pen = pens[penNum];
	pen.erase(pen.begin() + num);
	penInfo[penNum].totalNum--;
	penInfo[penNum].totalValue -= value;
	penInfo[penNum].totalWeight -= weight;

	auto& col = kindIndex[p->color];
	col.erase(find(col.begin(), col.end(), p));
	kindInfo[p->color].totalNum--;
	kindInfo[p->color].totalValue -= value;
	kindInfo[p->color].totalWeight -= weight;
}

void Factory::step(void)
{
	for (auto& color : kindIndex)
		for (auto& pig : color) {
			BasicPig::WeightType newW = pig->gainWeight();

		}
}

bool Factory::distribute(ptrToPig& p)
{
	SizeType pos;
	std::vector<SizeType> ablePos;
	
	for (pos = 0; pos < pens.size(); pos++) {
		if (pens[pos].empty()) {
			ablePos.push_back(pos);
			continue;
		}
		if ((PigNode::black == p->color && PigNode::black == pens[pos][0]->color) ||
			(PigNode::black == p->color && PigNode::black == pens[pos][0]->color))
			ablePos.push_back(pos);
	}
	
	pens[ablePos[rand() % ablePos.size()]].push_back(p);
	return !ablePos.empty();
}
