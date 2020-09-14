#include "Factory.h"
#include <algorithm>
#include <fstream>
#include <set>
farm::Factory::Factory(const char* saveName, const char* recordName, int mode) :
	day(0), money(500000), savingName(saveName), recordName(recordName)
{
	if (old == mode) {
		std::ifstream inf(savingName, std::ios::in);
		inf >> *this;
	}
	else {
		std::ofstream aa(savingName, std::ios::trunc);//删除原存档
		std::ofstream aaa(recordName, std::ios::trunc);//删除原记录
	}
}
farm::SizeType farm::Factory::pigNum(void) const
{
	return kindIndex[0].size() + kindIndex[1].size() + kindIndex[2].size();
}

farm::SizeType farm::Factory::pigNum(farm::Color c) const
{
	return kindIndex[c].size();
}

farm::SizeType farm::Factory::pigNum(farm::SizeType penNum) const
{
	return pens[penNum].size();
}

bool farm::Factory::purChase(Pigs::ptrToPig& victim) {
	if (money < victim->getCost())
		return false;
	if (false == distribute(victim))
		return false;
	money -= victim->getCost();
	std::ofstream(recordName, std::ios::app) << "day " << day << " buy:" << std::endl << *victim << std::endl;
	return true;
}

void farm::Factory::sellOut(void) {
	std::set<farm::SizeType> penNums;
	std::ofstream record(recordName, std::ios::app);
	record << "day " << day << " sell:" << std::endl;
	for (auto& pigs : kindIndex) {
		auto newEnd = std::partition(pigs.begin(), pigs.end(), [this, &penNums](Pigs::ptrToPig p) {
			if (p->isMature(day) && p->isHealthy() && !pens[p->getLocation()].getIllNum()) {
				penNums.insert(p->getLocation());
				return false;
			}
			return true;
			});

		std::for_each(newEnd, pigs.end(), [this,&record](const Pigs::ptrToPig& ptr)
			{
				record << *ptr << std::endl;
				money += ptr->getValue(); });
		pigs.erase(newEnd, pigs.end());
	}
	for (auto num : penNums) {
		auto& pen = pens[num];
		for (auto iter = pen.begin(); iter != pen.end();)
			if ((*iter)->isMature(day))
				iter = pen.erase(iter);
			else
				iter++;
	}
}

void farm::Factory::sell(farm::SizeType penNum)
{
	auto& pen = pens[penNum];
	if (!pen.illNum) {
		for (auto& pig : pen) {
			kindIndex[pig->getColor()].erase(pig);
			money += pig->getValue();
		}
		pen.clear();
	}
}

void farm::Factory::sell(farm::Color k)
{
	std::set<farm::SizeType> penNums;
	auto& pigs = kindIndex[k];
	auto newEnd = std::partition(pigs.begin(), pigs.end(), [this, &penNums](Pigs::ptrToPig p) {
		if (p->isMature(day) && p->isHealthy() && !pens[p->getLocation()].getIllNum()) {
			penNums.insert(p->getLocation());
			return true;
		}
		return false;
		});
	std::for_each(newEnd, pigs.end(), [this](const Pigs::ptrToPig& ptr) {money += ptr->getValue(); });
	pigs.erase(newEnd, pigs.end());

	for (auto num : penNums) {
		auto& pen = pens[num];
		for (auto iter = pen.begin(); iter != pen.end();)
			if ((*iter)->isMature(day) && (*iter)->isHealthy() && (*iter)->getColor() == k)
				iter = pen.erase(iter);
			else
				iter++;
	}
}

void farm::Factory::sell(Pigs::ptrToPig& p)
{
	if (p->isMature(day) && p->isHealthy() && !pens[p->getLocation()].getIllNum()) {
		money += p->getValue();
		kindIndex[p->getColor()].erase(p);
		pens[p->getLocation()].erase(p);
	}
}

void farm::Factory::kill(farm::SizeType penNum)
{
	quarantine.erase(penNum);
	auto& pen = pens[penNum];
	for (auto& pig : pen)
		kindIndex[pig->getColor()].erase(pig);
	pen.clear();
}

bool farm::Factory::spread(const farm::SizeType& pos, const int possibility) {
	auto& pen = pens[pos];
	bool flg = false;
	for (auto iter = pen.begin(); iter != pen.end();)
		if ((*iter)->isdying(day)) {
			kindIndex[(*iter)->getColor()].erase(*iter);
			iter = pen.erase(iter);
		}
		else {
			if ((*iter)->isHealthy() && (rand() % 100 < possibility)) {
				flg = true;
				(*iter)->setIll(day);
				pen.illNum++;
				kindIndex[(*iter)->getColor()].illNum++;
			}
			iter++;
		}
	return true;
}

void farm::Factory::save(void)
{
	std::ofstream(savingName) << *this;
}

void farm::Factory::step(void)
{
	farm::WeightType a[100] = { 0 };
	farm::MoneyType b[100] = { 0 };
	for (auto& k : kindIndex)
		for (auto& pig : k) {
			const farm::WeightType dw = pig->gainWeight();
			const farm::MoneyType dv = dw * BasicPig::getUnitValue(pig->getColor());
			k.totalWeight += dw;
			k.totalValue += dv;
			a[pig->getLocation()] += dw;
			b[pig->getLocation()] += dv;
		}
	for (int i = 0; i < 100; i++) {
		pens[i].totalWeight += a[i];
		pens[i].totalValue += b[i];
	}


	std::vector<farm::SizeType> newpos;
	for (auto qua = quarantine.begin(); qua != quarantine.end();) {
		spread(*qua, 50);
		if (*qua >= 1)
			if (spread(*qua - 1, 15))
				newpos.push_back(*qua - 1);
		if (*qua < 99)
			if (spread(*qua + 1, 15))
				newpos.push_back(*qua + 1);

		if (pens[*qua].empty()) qua = quarantine.erase(qua);
		else qua++;
	}
	for (auto pos : newpos)
		quarantine.insert(pos);
	day++;
}

farm::SizeType farm::Factory::BreakOut(void) {
	farm::SizeType pos = rand() % 100;
	while (pens[pos].empty())
		pos = rand() % 100;
	quarantine.insert(pos);
	return  pos;
}

bool farm::Factory::distribute(Pigs::ptrToPig& p) {
	farm::SizeType pos;
	std::vector<farm::SizeType> ablePos;

	for (pos = 0; pos < pens.size(); pos++) {
		auto& pen = pens[pos];
		if (pen.empty()) {
			ablePos.push_back(pos);
			continue;
		}
		if (((farm::black == p->getColor() && farm::black == pen[0]->getColor()) ||
			(farm::black != p->getColor() && farm::black != pen[0]->getColor()))
			&& !pen.getIllNum() && pen.size() < 9)
			ablePos.push_back(pos);
	}

	if (ablePos.empty())
		return false;
	pos = ablePos[rand() % ablePos.size()];
	p->set(day, pos);
	pens[pos].add(p);
	kindIndex[p->getColor()].add(p);
	return true;
}

std::istream& farm::operator>>(std::istream& is, Factory& fa)
{
	farm::SizeType pigNum;
	is >> fa.day >> pigNum >> fa.money;
	Pigs tmp;
	while (is >> tmp)
		for (auto& pig : tmp) {
			fa.kindIndex[pig->getColor()].add(pig);
			fa.pens[pig->getLocation()].add(pig);
		}
	return is;
}

std::ostream& farm::operator<<(std::ostream& os, const Factory& fa)
{
	os << fa.day << ' ' << fa.pigNum() << ' ' << fa.money << std::endl;
	for (const auto& pigs : fa.pens)
		if (!pigs.empty())
			os << pigs << std::endl;
	return os;
}
