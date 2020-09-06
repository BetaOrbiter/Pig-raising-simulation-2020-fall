#pragma once
#include <iostream>
#include "Typedef.h"
class BasicPig
{
public:	//�ӿ�
	BasicPig(Time t, farm::Color c = static_cast<farm::Color>(rand()%3), farm::WeightType w = rand()%40+60)//�����ṩʱ��
		:color(c),weight(w), health(true), penNum(farm::nsize), entryTime(t), illTime(ntime) {};//λ����distribute����
	BasicPig(std::istream& is);//�����д�����ʹ��>>�����

	static constexpr int getUnitCost(farm::Color c) { return unitCost[c]; }						//���ص�λ����ɱ�
	static constexpr int getUnitValue(farm::Color c) { return unitSellPrice[c]; }				//���ص�λ�ۼ�

	bool isMature(const Time& nowTime) {return ((nowTime-entryTime) >= 90) || (weight>=150);}	//��ǰ�Ƿ����
	farm::MoneyType getValue(void) const { return unitSellPrice[color] * weight; }				//��ǰ�ۼ�
	farm::WeightType getWeight(void) const { return weight; }									//��ǰ����
	farm::Color getColor(void) const { return color; }											//��ɫƷ��
	farm::WeightType gainWeight(void)															//��������
		{ farm::WeightType newW = static_cast<farm::WeightType>(rand() % 13) / 10;
			weight += newW;return newW; }
	bool isHealthy(void) const { return health; }												//�Ƿ񽡿�

	friend std::ostream& operator<<(std::ostream&,const BasicPig&);
	friend std::istream& operator>>(std::istream&, BasicPig&);		//���� ���� ��Ȧ��� ����ʱ�� ����״̬ ����ʱ�䣬����ȱ��
private://���ݳ�Ա
	static constexpr int unitSellPrice[3] = { 15, 7, 6 };
	static constexpr int unitCost[3] = { 20, 10, 9 };

	farm::Color color;			//����
	farm::WeightType weight;	//����
	farm::SizeType penNum;		//������Ȧ���
	Time entryTime;				//����ʱ��
	bool health;				//�������
	Time illTime;				//����ʱ��
};