#include <tuple>
#include <iostream>

#include "depart.h"

Depart& Depart::operator=(const Depart& d) {
    day = d.day;
    month = d.month;
    year = d.year;

    return *(this);
}

std::istream& operator>>(std::istream& os, Depart& d) {
    os >> d.year >> d.month >> d.day;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Depart& d) {
    os << d.year << " " << d.month << " " << d.day;
	return os;
}

bool Depart::operator<(const Depart& depart) {
    return std::make_tuple(year, month, day) < std::make_tuple(depart.year, depart.month, depart.day);
}
