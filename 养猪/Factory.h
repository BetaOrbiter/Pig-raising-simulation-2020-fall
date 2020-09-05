#pragma once
#include <array>
#include <vector>
#include <memory>
#include <iostream>
#include "BasicPig.h"

class Pig;

using Time = size_t;	//����ǣ�30��Ϊһ���£�360��Ϊһ�꣨�ǵ���͵���ˣ�

class Factory
{
public:
	using MoneyType = double;
	using ptrToPig = std::shared_ptr<Pig>;
	using Pigs = std::vector<ptrToPig>;
	using SizeType = size_t;

private:
	std::array<Pigs, 3> kindIndex;	//��������,��������ָ�����ָ��
	std::array<Pigs, 100> Pigpens;	//��Ȧ��������λ�ô�����ָ��,Ҳ����Ҫ������ʽ
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

	void purChase(BasicPig::Kind k, SizeType count);	//���ι����������
	void perChase(BasicPig::Kind k, BasicPig::WeightType w);//��׼����
	
	void sellOut(void);	//����������
	void sell(SizeType penNum);//��Ȧ��
	void sell(BasicPig::Kind k);//��������

	void getInfo(BasicPig::Kind k);		//������Ϣ(�����������أ�
	void getInfo(SizeType penNum);	//��Ȧ��Ϣ(����������(�Ƿ����)��������)
	void getInfo(SizeType penNum);//ĳȦĳͷ����Ϣ(���࣬���أ�����ʱ�䣬����λ��)

	void step(void);//һ���ȥ�������أ�������
private:
	void distribute(const ptrToPig &ptr)//������������Ȧ����
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

	Time entryTime;	//����ʱ��
	Factory::SizeType pigPenNum;	//������Ȧ���
	Factory::SizeType num;			//��Ȧ�ڲ����
};