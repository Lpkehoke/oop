#pragma once

#include <string>
#include <iostream>

struct Theme {
    std::string name;
    std::string developer;
    int         group;
    int         date_plan = -1;
    int         date_real = -1;
};

std::istream& operator>>(std::istream& os, Theme& d);
std::ostream& operator<<(std::ostream& os, const Theme& d);
