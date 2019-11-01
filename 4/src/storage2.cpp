#include <iostream>
#include <cstddef>

#include "storage2.hpp"

Storage2::Storage2(std::string_view t_fam, double t_price, int t_quant, const Date& d) noexcept
	: Base_storage(t_fam, t_price, t_quant)
    , date(d)
{}


bool Storage2::operator> (const Storage2& other) const noexcept {
    return date > other.date;
}


bool Storage2::operator> (const Date& other) const noexcept {
    return date > other;
}
