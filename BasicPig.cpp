#include "BasicPig.h"
#include <cstring>
static constexpr  char const* colorName[]{ "black","stripe","white" };
static constexpr char const* healthName[]{ "ill","healthy" };

std::ostream& operator<<(std::ostream& os, const BasicPig& p)
{
	return os << colorName[p.color] << " weight: " << p.weight << " location: " << static_cast<long long>(p.penNum) << " entryTime: " << static_cast<long long>(p.entryTime) << ' '
		<< healthName[p.health] << " illtime: " << static_cast<long long>(p.illTime);
}

std::istream& operator>>(std::istream& is, BasicPig& p)
{
    char colorIn[7], healthIn[8], useless[30];//useless数组过滤输出时的说明信息
	is >> colorIn >> useless >> p.weight >> useless >> p.penNum >> useless >> p.entryTime >> healthIn >> useless >> p.illTime;

    for(int i=0;i<3;i++)//设置颜色
		if (!strncmp(colorName[i], colorIn, 6)) {
			p.color = static_cast<farm::Color>(i);
			break;
		}

    p.health = static_cast<bool>(strncmp(healthName[0], healthIn, 3));
	return is;
}

BasicPig::BasicPig(std::istream& is):BasicPig()
{
	is >> *this;
}
