#include <iostream>
#include <cstddef>

#include "storage.hpp"

std::ostream& operator<< (std::ostream& os, const Storage& item) {
    os << item.fam << "\t\t\t" << item.price << "\t\t\t" << item.quant << "\t\t\t" << item.num << std::endl;
    return (os);
}

Storage::Storage(std::string_view t_fam, double t_price, int t_quant, int t_num)
    : fam(t_fam)
    , price(t_price)
    , quant(t_quant)
    , num(t_num)
{
    ++Storage::count;
}

Storage::Storage(const Storage& other) {
	fam   = other.fam;
	price = other.price;
	quant = other.quant;
	num   = other.num;
	date  = other.date;

	++Storage::count;
}


Storage& Storage::operator=(const Storage& other) {
	fam   = other.fam;
	price = other.price;
	quant = other.quant;
	num   = other.num;
	date  = other.date;

	++Storage::count;
	return *this;
}


std::size_t Storage::count = 0;
