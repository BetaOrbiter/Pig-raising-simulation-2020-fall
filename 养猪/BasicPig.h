#pragma once
#include <iostream>
#include "Typedef.h"
class BasicPig
{
public:	//接口
	BasicPig(farm::Color c = static_cast<farm::Color>(rand()%3), farm::WeightType w = rand()%40+60)
		:color(c),weight(w), health(true), penNum(farm::nsize), entryTime(ntime), illTime(ntime) {};//位置时间在分配时写入
	BasicPig(std::istream& is);//从流中创建，使用>>运算符

	static constexpr int getUnitCost(farm::Color c) { return unitCost[c]; }						//返回单位购买成本
	static constexpr int getUnitValue(farm::Color c) { return unitSellPrice[c]; }				//返回单位售价

	bool isMature(const Time& nowTime) {return ((nowTime-entryTime) >= 90) || (weight>=150);}	//当前是否成熟
	farm::MoneyType getCost(void) const { return unitCost[color] * weight; }
	farm::MoneyType getValue(void) const { return unitSellPrice[color] * weight; }				//当前售价
	farm::WeightType getWeight(void) const { return weight; }									//当前体重
	farm::Color getColor(void) const { return color; }											//颜色品种
	farm::SizeType getLocation()const { return penNum; }										//所在猪圈编号
	farm::WeightType gainWeight(void)															//增长体重
		{ farm::WeightType newW = static_cast<farm::WeightType>(rand() % 13) / 10;
			weight += newW;return newW; }
	void set(Time& t, farm::SizeType pen) { entryTime = t; penNum = pen; }						//烙猪，烙下入栏时间与圈号
	void setIll(Time t) { health = false; entryTime = t; }										//设为生病
	bool isHealthy(void) const { return health; }												//是否健康
	bool isdying(Time t) { return t - illTime > 3; }											//发病三天死亡
	friend std::ostream& operator<<(std::ostream&,const BasicPig&);
	friend std::istream& operator>>(std::istream&, BasicPig&);		//种类 质量 猪圈编号 入栏时间 健康状态 生病时间，不可缺少
private://数据成员
	static constexpr int unitSellPrice[3] = { 15, 7, 6 };
	static constexpr int unitCost[3] = { 20, 10, 9 };

	farm::Color color;			//种类
	farm::WeightType weight;	//质量
	farm::SizeType penNum;		//所在猪圈标号
	Time entryTime;				//入栏时间
	bool health;				//健康与否
	Time illTime;				//生病时间
};