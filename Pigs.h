#pragma once
#include "Typedef.h"
#include "BasicPig.h"
#include <vector>
#include <iostream>

namespace farm {
	class Pigs {//包含了猪群的简略信息与索引
				//使Factory不那么复杂
				//封装vector类，添加了几个统计信息,由本类与Factory共同维护
		friend class Factory;
		friend std::istream& operator>>(std::istream&, farm::Pigs&);
		friend std::ostream& operator<<(std::ostream&, const farm::Pigs&);
    //类型定义
	public:
		using ptrToPig = std::shared_ptr<BasicPig>;
	private:
		using iterator = std::vector<ptrToPig>::iterator;
		using riterator = std::vector<ptrToPig>::reverse_iterator;
	
    //接口
	public:
		Pigs(SizeType num = 0);//随机生成一批猪，时间，位置分配时指定

		farm::MoneyType getValue(void) const { return totalValue; }
		farm::WeightType getWeight(void) const { return totalWeight; }
		farm::SizeType getIllNum(void) const { return illNum; }

		bool empty(void) const { return Index.empty(); }
		farm::SizeType size(void) const { return Index.size(); }
		ptrToPig& operator[](farm::SizeType s) { return Index[s]; }
		iterator begin() {return Index.begin();}
		iterator end() { return Index.end(); }

		Pigs& add(ptrToPig& ptr);
		void clear(void);
		iterator erase(iterator beg, iterator end);
		iterator erase(iterator target);
		iterator erase(const farm::SizeType pos);
		iterator erase(const farm::Pigs::ptrToPig& ptr);

    //数据类型
    private:
		farm::WeightType totalWeight;
		farm::MoneyType totalValue;
		std::vector<ptrToPig> Index;
		farm::SizeType illNum = 0;
	};

	std::istream& operator>>(std::istream&, farm::Pigs&);
	std::ostream& operator<< (std::ostream&,const farm::Pigs&);
}
