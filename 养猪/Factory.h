#pragma once
#include <array>
#include <vector>
#include <memory>
#include <iostream>
#include "BasicPig.h"

class PigNode;
using ptrToPig = std::shared_ptr<PigNode>;
using Pigs = std::vector<ptrToPig>;

using Time = size_t;	//����ǣ�30��Ϊһ���£�360��Ϊһ�꣨�ǵ���͵���ˣ�

class Factory
{
public://���Ͷ���
	using MoneyType = double;
	using SizeType = size_t;
	static constexpr SizeType nsize = 0xFFFFFFFFFFFFFFFF;

private://���ݳ�Ա
	//ȫ��̬����
	std::array<Pigs, 3> kindIndex;	//��������,��������ָ�����ָ��
	std::array<Pigs, 100> pens;	//��Ȧ��������λ�ô�����ָ��,Ҳ����Ҫ������ʽ
	
	struct Info {//ͳ����Ϣ�ṹ��
		SizeType totalNum = 0;//������
		BasicPig::WeightType totalWeight = 0;
		MoneyType totalValue = 0;
	};
	std::array<Info, 100> penInfo;
	std::array<Info, 3> kindInfo;
	
	MoneyType money;

public://��Ա����
	Factory() :money(1000) {};
	Factory(std::istream&);

	MoneyType getMoney(void) { return money; }
	
	SizeType pigNum(void);
	SizeType pigNum(BasicPig::Color);
	SizeType pigNum(SizeType penNum);

	bool purChase(ptrToPig& victim);
	
	void sellOut(void);	//����������
	void sell(SizeType penNum);//��Ȧ��
	void sell(BasicPig::Color k);//��������
	void sell(ptrToPig& p);

	void getInfo(BasicPig::Color k);		//������Ϣ(�����������أ�
	void getInfo(SizeType penNum);	//��Ȧ��Ϣ(����������(�Ƿ����)��������)
	void getInfo(SizeType penNum, SizeType num);//ĳȦĳͷ����Ϣ(���࣬���أ�����ʱ�䣬����λ��)

	friend Info& operator-=(Info& in, const ptrToPig&);
	friend Info& operator+=(Info& in, const ptrToPig&);

	void step(void);//һ���ȥ�������أ�������
private:
	bool distribute(ptrToPig& p);//������������Ȧ����,���سɹ����
};

Pigs generate(Factory::SizeType num);

class PigNode
	:public BasicPig
{
	friend class Factory;
	friend Pigs generate(Factory::SizeType);
public:
	PigNode(Time t, BasicPig::Color k, BasicPig::WeightType w)//λ��,ʱ����distribute����
		:BasicPig(k,w), entryTime(t), penNum(Factory::nsize), num(Factory::nsize) {};
	PigNode(std::istream& is);


	Factory::MoneyType cost(void) { return purchasePrice[color]; }
	Factory::MoneyType getValue(void) { return unitSellPrice[color]*weight; }
	bool isMature();
private:
	static constexpr int unitSellPrice[3] = { 15, 7, 6 };
	static constexpr int purchasePrice[3] = { 15 * 3, 7 * 3, 6 * 3 };

	Time entryTime;	//����ʱ��
	Factory::SizeType penNum;	//������Ȧ���
	Factory::SizeType num;			//��Ȧ�ڲ����
};