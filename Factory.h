#pragma once
#include <array>
#include <fstream>
#include <set>
#include "Typedef.h"
#include "Pigs.h"
namespace farm {
    class
            Factory
	{
	public:
		static constexpr int newF = 0;
		static constexpr int old = 1;

	private://数据成员

		std::array<Pigs, 3> kindIndex;	//种类索引,按种类存放指向猪的指针
		std::array<Pigs, 100> pens;	//猪圈索引，按位置存放猪的指针,也是主要索引方式
		std::set <farm::SizeType> quarantine;
		farm::MoneyType money;
		Time day;

        const std::string savingName;
        const std::string recordName;
	public://成员函数
		//Factory(farm::MoneyType m = 10000) :money(m),day(0) {};
		Factory(const char* saveName, const char* recordName, int mode);

		farm::MoneyType getMoney(void) const { return money; }
		Time getDay(void) const { return day; }
        farm::SizeType illNum(void) const//查询病猪数量
		{
			return kindIndex[0].getIllNum() + kindIndex[1].getIllNum() + kindIndex[2].getIllNum();
		}
        farm::WeightType getWeight(void) const//查询总重量
		{
			return kindIndex[0].getWeight() + kindIndex[1].getWeight() + kindIndex[2].getWeight();
		}
        farm::MoneyType getValue(void) const//查询总价值
		{
			return kindIndex[0].getValue() + kindIndex[1].getValue() + kindIndex[2].getValue();
		}
        farm::SizeType pigNum(void) const;//查询总数
        farm::SizeType pigNum(farm::Color) const;//查询这个颜色的总数
        farm::SizeType pigNum(farm::SizeType penNum) const;//查这个圈的总数

        bool purChase(Pigs::ptrToPig& victim);//购买并自动分配猪，返回是否成功

		void sellOut(void);	//能卖的卖光
		void sell(farm::SizeType penNum);//按圈卖
		void sell(farm::Color k);//按种类卖
        void sell(Pigs::ptrToPig& p);//精确卖

        void kill(farm::SizeType penNum);//扑杀该圈

		Pigs& operator[](const farm::SizeType penNum) { return pens[penNum]; }
        Pigs& operator[](const farm::Color col) { return kindIndex[col]; }

		friend std::ostream& operator<<(std::ostream& os, const Factory& fa);
		friend std::istream& operator>>(std::istream& is, Factory& fa);
        void save(void);//保存文件

		void step(void);//一天过去，涨体重，传播猪瘟
        farm::SizeType BreakOut(void);//找个猪圈投病毒
	private:
		bool spread(const farm::SizeType& pos, const int possibility);//在pens[pos]传染病毒，机率从0到100
		bool distribute(Pigs::ptrToPig& p);//将买入的猪加入圈索引,填入时间,返回成功与否
	};
	std::istream& operator>> (std::istream& is, Factory& fa);
	std::ostream& operator<<(std::ostream& os, const Factory& fa);
}
