#include <iostream>
#include <cstddef>

#include "storage.hpp"

std::ostream& operator<< (std::ostream& os, const Storage& item) {
    os << item.fam << "\t\t\t" << item.price << "\t\t\t" << item.quant << "\t\t\t" << item.num  << "\t\t\t" << item.date << std::endl;
    return os;
}

Storage::Storage(std::string_view t_fam, double t_price, int t_quant, int t_num, const Date& d) noexcept
	: Base_storage(t_fam, t_price, t_quant)
	, Storage1(t_fam, t_price, t_quant, t_num)
	, Storage2(t_fam, t_price, t_quant, d)
{}

void Storage::operator! () noexcept {
    shelfLife = !shelfLife;
}

void Storage::show() const noexcept {
	std::cout << *this << std::endl;
}
