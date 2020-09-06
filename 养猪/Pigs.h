#pragma once
#include "Typedef.h"
#include "BasicPig.h"
#include <vector>
#include <iostream>
#include <algorithm>

namespace farm {
	class Pigs {//��������Ⱥ�ļ�����Ϣ������
				//��װvector�࣬����˼���ͳ����Ϣ
		using ptrToPig = std::shared_ptr<BasicPig>;
	public:
		Pigs(Time t = ntime, SizeType num = 0);//�������һ��������ָ��ʱ��

		friend std::istream& operator>>(std::istream&, farm::Pigs&);
		friend std::ostream& operator<<(std::ostream&, const farm::Pigs&);

		farm::MoneyType getValue(void) const { return totalValue; }
		farm::WeightType getWeight(void) const { return totalWeight; }
		farm::WeightType getNum(void) const { return Index.size(); }

		Pigs& add(ptrToPig& ptr);
		Pigs& erase(const farm::SizeType pos);
		Pigs& erase(const farm::Pigs::ptrToPig& ptr);
	private:

		farm::WeightType totalWeight;
		farm::MoneyType totalValue;
		std::vector<ptrToPig> Index;
		farm::SizeType illNum = 0;
	};

	std::istream& operator>>(std::istream&, farm::Pigs&);
	std::ostream& operator<< (std::ostream&, farm::Pigs&);
}