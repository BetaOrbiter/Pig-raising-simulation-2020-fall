#pragma once
#include <array>
#include <memory>
#include <iostream>
#include "Typedef.h"
#include "Pigs.h"
namespace farm {
	class Factory
	{
	private://数据成员
		//全动态分配

		std::array<Pigs, 3> kindIndex;	//种类索引,按种类存放指向猪的指针
		std::array<Pigs, 100> pens;	//猪圈索引，按位置存放猪的指针,也是主要索引方式
		farm::MoneyType money;

	public://成员函数
		Factory(const Time& t) :money(5000) {};
		Factory(std::istream&);

		farm::MoneyType getMoney(void) { return money; }

		farm::SizeType pigNum(void) const;
		farm::SizeType pigNum(farm::Color) const;
		farm::SizeType pigNum(farm::SizeType penNum) const;

		bool purChase(Pigs::ptrToPig & victim);

		void sellOut(void);	//能卖的卖光
		void sell(farm::SizeType penNum);//按圈卖
		void sell(farm::Color k);//按种类卖
		void sell(Pigs::ptrToPig& p);

		Pigs& operator[](const farm::SizeType penNum);
		Pigs& operator[](const farm::Color col);

		friend std::ostream& operator<<(std::ostream& os, const Pigs&);
		friend std::ostream& operator<<(std::ostream& os, const Factory& fa);

		void step(void);//一天过去，涨体重，得猪瘟
	private:
		bool distribute(ptrToPig& p);//将买入的猪加入圈索引,返回成功与否
	};

	std::ostream& operator<<(std::ostream& os, const farm::Pigs&);
	std::ostream& operator<<(std::ostream& os, const Factory& fa);
}