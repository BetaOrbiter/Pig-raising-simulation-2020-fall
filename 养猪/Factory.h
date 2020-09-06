#pragma once
#include <array>
#include <memory>
#include <iostream>
#include "Typedef.h"
#include "Pigs.h"
namespace farm {
	class Factory
	{
	private://���ݳ�Ա
		//ȫ��̬����

		std::array<Pigs, 3> kindIndex;	//��������,��������ָ�����ָ��
		std::array<Pigs, 100> pens;	//��Ȧ��������λ�ô�����ָ��,Ҳ����Ҫ������ʽ
		farm::MoneyType money;

	public://��Ա����
		Factory(const Time& t) :money(5000) {};
		Factory(std::istream&);

		farm::MoneyType getMoney(void) { return money; }

		farm::SizeType pigNum(void) const;
		farm::SizeType pigNum(farm::Color) const;
		farm::SizeType pigNum(farm::SizeType penNum) const;

		bool purChase(Pigs::ptrToPig & victim);

		void sellOut(void);	//����������
		void sell(farm::SizeType penNum);//��Ȧ��
		void sell(farm::Color k);//��������
		void sell(Pigs::ptrToPig& p);

		Pigs& operator[](const farm::SizeType penNum);
		Pigs& operator[](const farm::Color col);

		friend std::ostream& operator<<(std::ostream& os, const Pigs&);
		friend std::ostream& operator<<(std::ostream& os, const Factory& fa);

		void step(void);//һ���ȥ�������أ�������
	private:
		bool distribute(ptrToPig& p);//������������Ȧ����,���سɹ����
	};

	std::ostream& operator<<(std::ostream& os, const farm::Pigs&);
	std::ostream& operator<<(std::ostream& os, const Factory& fa);
}