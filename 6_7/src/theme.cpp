#include <iostream>

#include "theme.h"

std::istream& operator>>(std::istream& os, Theme& d) {
    os >> d.name >> d.group >> d.developer >> d.date_plan;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Theme& d) {
	os << d.name << "\t\t\t" << d.group << "\t\t\t" << d.developer << "\t\t\t" << d.date_plan << std::endl;
	return os;
}
