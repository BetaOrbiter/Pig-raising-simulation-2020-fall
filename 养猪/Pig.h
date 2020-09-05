#pragma once
#include "Time.h"
#include <iostream>
#include <cstdlib>

class Pig
{
	static constexpr int unitSellPrice[3] = { 15, 7, 6 };
	static constexpr int purchasePrice[3] = { 15 * 3, 7 * 3, 6 * 3 };
	enum Kind { black, stripe, stripe };

	Pig(Time t, size_t pN, size_t n, Kind k = (Kind)rand() % 3, double w = rand() % 60 + 40)
		:kind(k), weight(w), entryTime(t), pigPenNum(pN), num(n) {};
	Pig(std::istream &is);

	friend std::istream& operator>> (std::istream& is, const Pig& pig);
	friend std::ostream& operator<< (std::ostream& os, const Pig& pig);


	Kind kind;			//����
	double weight;		//����
	Time entryTime;	//����ʱ��
	size_t pigPenNum;	//������Ȧ���
	size_t num;			//��Ȧ�ڲ����
};