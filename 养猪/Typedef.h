#pragma once
namespace farm {
	enum Color { black, stripe, white };
	using WeightType = double;

	using MoneyType = double;
	using SizeType = size_t;
	static constexpr SizeType nsize = static_cast<SizeType>(-1);

	class Factory;
	class Pigs;
}
using Time = size_t;
static constexpr Time ntime = static_cast<Time>(-1);
