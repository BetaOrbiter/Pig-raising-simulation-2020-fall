#pragma once
#include <array>
#include <vector>
#include <memory>
#include <iostream>
#include "BasicPig.h"

class Pig;

using Time = size_t;	//以天记，30天为一个月，360天为一年（是的我偷懒了）

class Factory
{
public:
	using MoneyType = double;
	using ptrToPig = std::shared_ptr<Pig>;
	using Pigs = std::vector<ptrToPig>;
	using SizeType = size_t;

private:
	std::array<Pigs, 3> kindIndex;	//种类索引,按种类存放指向猪的指针
	std::array<Pigs, 100> Pigpens;	//猪圈索引，按位置存放猪的指针,也是主要索引方式
	MoneyType money;

public:
	Factory();
	Factory(std::istream&);

	friend std::istream& operator>>(std::istream& is, Factory& fc);
	friend std::ostream& operator<<(std::ostream& os, const Factory& fc);
	MoneyType getMoney(void) { return money; }
	
	SizeType pigNum(void);
	SizeType pigNum(BasicPig::Kind);
	SizeType pigNum(SizeType penNum);

	void purChase(BasicPig::Kind k, SizeType count);	//批次购买，随机重量
	void perChase(BasicPig::Kind k, BasicPig::WeightType w);//精准购买
	
	void sellOut(void);	//能卖的卖光
	void sell(SizeType penNum);//按圈卖
	void sell(BasicPig::Kind k);//按种类卖

	void getInfo(BasicPig::Kind k);		//种类信息(数量，总体重）
	void getInfo(SizeType penNum);	//按圈信息(数量，种类(是否黑猪)，总体重)
	void getInfo(SizeType penNum);//某圈某头的信息(种类，体重，入栏时间，所在位置)

	void step(void);//一天过去，涨体重，得猪瘟
private:
	void distribute(const ptrToPig &ptr)//将买入的猪加入圈索引
};

class Pig
	:private BasicPig
{
	friend class Factory;
	
	Pig(Time t, Factory::SizeType penNum, Factory::SizeType num, BasicPig::Kind k, BasicPig::WeightType w)
		:BasicPig(k,w), entryTime(t), pigPenNum(penNum), num(num) {};
	Pig(std::istream& is);

	friend std::istream& operator>> (std::istream& is, const Pig& pig);
	friend std::ostream& operator<< (std::ostream& os, const Pig& pig);

	Factory::MoneyType value(void) { return weight * unitSellPrice[kind]; }

	Time entryTime;	//入栏时间
	Factory::SizeType pigPenNum;	//所在猪圈标号
	Factory::SizeType num;			//猪圈内部编号
};