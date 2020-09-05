#pragma once
#include <iostream>
class BasicPig
{
public:
	static constexpr int unitSellPrice[3] = { 15, 7, 6 };
	static constexpr int purchasePrice[3] = { 15 * 3, 7 * 3, 6 * 3 };
	
	enum Kind { black, stripe, white };
	using WeightType = double;
	BasicPig(Kind k, WeightType w) :kind(k), weight(w) {};

	WeightType getWeight(void) { return weight; }
	Kind getKind(void) { return kind; }
	void gainWeight(void) { weight += double(rand() % 13) / 10; }

protected:
	Kind kind;			//种类
	double weight;		//质量
};