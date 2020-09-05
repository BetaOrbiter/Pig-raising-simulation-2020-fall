#pragma once
#include <array>
#include <vector>
#include <memory>
#include <iostream>
#include "BasicPig.h"

class PigNode;
using ptrToPig = std::shared_ptr<PigNode>;
using Pigs = std::vector<ptrToPig>;

using Time = size_t;	//以天记，30天为一个月，360天为一年（是的我偷懒了）

class Factory
{
public://类型定义
	using MoneyType = double;
	using SizeType = size_t;
	static constexpr SizeType nsize = 0xFFFFFFFFFFFFFFFF;

private://数据成员
	//全动态分配
	std::array<Pigs, 3> kindIndex;	//种类索引,按种类存放指向猪的指针
	std::array<Pigs, 100> pens;	//猪圈索引，按位置存放猪的指针,也是主要索引方式
	
	struct Info {//统计信息结构体
		SizeType totalNum = 0;//猪数量
		BasicPig::WeightType totalWeight = 0;
		MoneyType totalValue = 0;
	};
	std::array<Info, 100> penInfo;
	std::array<Info, 3> kindInfo;
	
	MoneyType money;

public://成员函数
	Factory() :money(1000) {};
	Factory(std::istream&);

	MoneyType getMoney(void) { return money; }
	
	SizeType pigNum(void);
	SizeType pigNum(BasicPig::Color);
	SizeType pigNum(SizeType penNum);

	bool purChase(ptrToPig& victim);
	
	void sellOut(void);	//能卖的卖光
	void sell(SizeType penNum);//按圈卖
	void sell(BasicPig::Color k);//按种类卖
	void sell(ptrToPig& p);

	void getInfo(BasicPig::Color k);		//种类信息(数量，总体重）
	void getInfo(SizeType penNum);	//按圈信息(数量，种类(是否黑猪)，总体重)
	void getInfo(SizeType penNum, SizeType num);//某圈某头的信息(种类，体重，入栏时间，所在位置)

	friend Info& operator-=(Info& in, const ptrToPig&);
	friend Info& operator+=(Info& in, const ptrToPig&);

	void step(void);//一天过去，涨体重，得猪瘟
private:
	bool distribute(ptrToPig& p);//将买入的猪加入圈索引,返回成功与否
};

Pigs generate(Factory::SizeType num);

class PigNode
	:public BasicPig
{
	friend class Factory;
	friend Pigs generate(Factory::SizeType);
public:
	PigNode(Time t, BasicPig::Color k, BasicPig::WeightType w)//位置,时间由distribute分配
		:BasicPig(k,w), entryTime(t), penNum(Factory::nsize), num(Factory::nsize) {};
	PigNode(std::istream& is);


	Factory::MoneyType cost(void) { return purchasePrice[color]; }
	Factory::MoneyType getValue(void) { return unitSellPrice[color]*weight; }
	bool isMature();
private:
	static constexpr int unitSellPrice[3] = { 15, 7, 6 };
	static constexpr int purchasePrice[3] = { 15 * 3, 7 * 3, 6 * 3 };

	Time entryTime;	//入栏时间
	Factory::SizeType penNum;	//所在猪圈标号
	Factory::SizeType num;			//猪圈内部编号
};