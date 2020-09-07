#pragma once
#include "Typedef.h"
#include "BasicPig.h"
#include <vector>
#include <iostream>

namespace farm {
	class Pigs {//��������Ⱥ�ļ�����Ϣ������
				//ʹFactory����ô����
				//��װvector�࣬����˼���ͳ����Ϣ,�ɱ�����Factory��ͬά��
		friend class Factory;
		friend std::istream& operator>>(std::istream&, farm::Pigs&);
		friend std::ostream& operator<<(std::ostream&, const farm::Pigs&);

	public:
		using ptrToPig = std::shared_ptr<BasicPig>;
	private:
		using iterator = std::vector<ptrToPig>::iterator;
		using riterator = std::vector<ptrToPig>::reverse_iterator;
	
	public:
		Pigs(SizeType num = 0);//�������һ����ʱ�䣬λ�÷���ʱָ��

		farm::MoneyType getValue(void) const { return totalValue; }
		farm::WeightType getWeight(void) const { return totalWeight; }
		farm::SizeType getIllNum(void) const { return illNum; }

		bool empty(void) const { return Index.empty(); }
		farm::SizeType size(void) const { return Index.size(); }
		ptrToPig& operator[](farm::SizeType s) { return Index[s]; }
		iterator begin() {return Index.begin();}
		iterator end() { return Index.end(); }
//		riterator rbegin() { return Index.rbegin(); }
//		riterator rend() { return Index.rend(); }

		Pigs& add(ptrToPig& ptr);
		iterator erase(iterator beg, iterator end);
		iterator erase(iterator target);
		Pigs& erase(const farm::SizeType pos);
		Pigs& erase(const farm::Pigs::ptrToPig& ptr);
	private:
		farm::WeightType totalWeight;
		farm::MoneyType totalValue;
		std::vector<ptrToPig> Index;
		farm::SizeType illNum = 0;
	};

	std::istream& operator>>(std::istream&, farm::Pigs&);
	std::ostream& operator<< (std::ostream&,const farm::Pigs&);
}