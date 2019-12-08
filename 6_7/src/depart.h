#pragma once

#include <iostream>


struct Depart {
    int day;
    int month;
    int year;

    Depart& operator=(const Depart& depart);
    bool operator<(const Depart& depart);
};

std::istream& operator>>(std::istream& os, Depart& d);
std::ostream& operator<<(std::ostream& os, const Depart& d);
