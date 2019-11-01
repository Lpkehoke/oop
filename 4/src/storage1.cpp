#include <iostream>
#include <cstddef>

#include "storage1.hpp"

Storage1::Storage1(std::string_view t_fam, double t_price, int t_quant, int t_num) noexcept
	: Base_storage(t_fam, t_price, t_quant)
	, num(t_num)
{
	++count;
}

Storage1::Storage1(const Storage1& other) noexcept
	: Base_storage(other)
	, num(other.num)
{
	++Storage1::count;
}


Storage1& Storage1::operator=(const Storage1& other) noexcept {
	fam   = other.fam;
	price = other.price;
	quant = other.quant;
	num   = other.num;

	++Storage1::count;
	return *this;
}

int Storage1::getNum() const noexcept {
	return num;
}

std::size_t Storage1::count = 0;
