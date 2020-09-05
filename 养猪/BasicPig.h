#pragma once
#include <iostream>
class BasicPig
{
public:	
	enum Color { black, stripe, white };
	using WeightType = double;
	BasicPig(Color k, WeightType w) :color(k), weight(w),health(true) {};

	WeightType getWeight(void) { return weight; }
	Color getColor(void) { return color; }
	WeightType gainWeight(void) { WeightType newW = WeightType(rand() % 13) / 10; weight += newW; return newW; }
	bool isHealthy(void) { return health; }
protected:
	Color color;			//种类
	WeightType weight;		//质量
	bool health;		//健康与否
};