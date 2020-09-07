#include "BasicPig.h"
#include <cstring>
static constexpr  char const* colorName[]{ "black","stripe","white" };
static constexpr char const* healthName[]{ "ill","healthy" };
std::ostream& operator<<(std::ostream& os, const BasicPig& p)
{
	return os << colorName[p.color] << "   " << p.weight << "   " << p.penNum << ' ' << p.entryTime << ' '
		<< healthName[p.health] << "   " << p.illTime;
}

std::istream& operator>>(std::istream& is, BasicPig& p)
{
	char colorIn[7], healthIn[8];
	is >> colorIn >> p.weight >> p.penNum >> p.entryTime >> healthIn >> p.illTime;
	for(int i=0;i<3;i++)
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