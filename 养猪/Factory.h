#pragma once
#include <array>
#include <iostream>
#include <set>
#include "Typedef.h"
#include "Pigs.h"
namespace farm {
	class Factory
	{
	private://���ݳ�Ա

		std::array<Pigs, 3> kindIndex;	//��������,��������ָ�����ָ��
		std::array<Pigs, 100> pens;	//��Ȧ��������λ�ô�����ָ��,Ҳ����Ҫ������ʽ
		std::set <farm::SizeType> quarantine;
		farm::MoneyType money;
		Time day;
	public://��Ա����
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

		void sellOut(void);	//����������
		void sell(farm::SizeType penNum);//��Ȧ��
		void sell(farm::Color k);//��������
		void sell(Pigs::ptrToPig& p);

		Pigs& operator[](const farm::SizeType penNum) { return pens[penNum]; }
		Pigs& operator[](const farm::Color col) { return kindIndex[col]; }

		friend std::ostream& operator<<(std::ostream& os, const Factory& fa);
		friend std::istream& operator>>(std::istream& is, Factory& fa);

		void step(void);//һ���ȥ�������أ�������
	private:
		bool distribute(Pigs::ptrToPig& p);//������������Ȧ����,����ʱ��,���سɹ����
	};
	std::istream& operator>> (std::istream& is, Factory& fa);
	std::ostream& operator<<(std::ostream& os, const Factory& fa);
}