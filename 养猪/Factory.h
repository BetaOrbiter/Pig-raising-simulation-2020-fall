#pragma once
#include <array>
#include <iostream>
#include <set>
#include "Typedef.h"
#include "Pigs.h"
namespace farm {
	class Factory
	{
	private://数据成员

		std::array<Pigs, 3> kindIndex;	//种类索引,按种类存放指向猪的指针
		std::array<Pigs, 100> pens;	//猪圈索引，按位置存放猪的指针,也是主要索引方式
		std::set <farm::SizeType> quarantine;
		farm::MoneyType money;
		Time day;
	public://成员函数
		Factory(farm::MoneyType m = 10000) :money(m),day(0) {};
		Factory(std::istream&);

		farm::MoneyType getMoney(void) const { return money; }
		Time getDay(void) const { return day; }
		farm::SizeType illNum(void) const
		{ return kindIndex[0].getIllNum() + kindIndex[1].getIllNum() + kindIndex[2].getIllNum(); }

		farm::SizeType pigNum(void) const;
		farm::SizeType pigNum(farm::Color) const;
		farm::SizeType pigNum(farm::SizeType penNum) const;

		bool purChase(Pigs::ptrToPig & victim);

		void sellOut(void);	//能卖的卖光
		void sell(farm::SizeType penNum);//按圈卖
		void sell(farm::Color k);//按种类卖
		void sell(Pigs::ptrToPig& p);

		Pigs& operator[](const farm::SizeType penNum) { return pens[penNum]; }
		Pigs& operator[](const farm::Color col) { return kindIndex[col]; }

		friend std::ostream& operator<<(std::ostream& os, const Factory& fa);
		friend std::istream& operator>>(std::istream& is, Factory& fa);

		void step(void);//一天过去，涨体重，得猪瘟
	private:
		bool distribute(Pigs::ptrToPig& p);//将买入的猪加入圈索引,填入时间,返回成功与否
	};
	std::istream& operator>> (std::istream& is, Factory& fa);
	std::ostream& operator<<(std::ostream& os, const Factory& fa);
}