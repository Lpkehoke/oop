#include <iostream>
#include <tuple>

#include "date.hpp"

std::ostream& operator<< (std::ostream& os, const Date& date) {
    os << date.year << "\t\t\t" << date.month << "\t\t\t" << date.day << std::endl;
    return os;
}

std::istream& operator>> (std::istream& os, Date& date) {
    os >> date.year >> date.month >> date.day;
    return os;
}

bool Date::operator> (const Date& other) const noexcept {
    return (std::tuple{year, month, day} > std::tuple{other.year, other.month, other.day});
}
