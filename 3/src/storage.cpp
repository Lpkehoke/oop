#include <iostream>
#include <cstddef>

#include "storage.hpp"

std::ostream& operator<< (std::ostream& os, const Storage& item) {
    os << item.fam << "\t\t\t" << item.price << "\t\t\t" << item.quant << "\t\t\t" << item.num  << "\t\t\t" << item.date << std::endl;
    return (os);
}

Storage::Storage(std::string_view t_fam, double t_price, int t_quant, int t_num, const Date& d)
    : fam(t_fam)
    , price(t_price)
    , quant(t_quant)
    , num(t_num)
    , date(d)
{
    ++Storage::count;
}

bool Storage::operator> (const Storage& other) const noexcept {
    return date > other.date;
}


bool Storage::operator> (const Date& other) const noexcept {
    return date > other;
}


void Storage::operator! () noexcept {
    shelfLife = !shelfLife;
}

std::size_t Storage::count = 0;
