#pragma once

#include <iostream>

class Date final {
    public:
        friend std::ostream& operator<< (std::ostream& os, const Date& item);
        friend std::istream& operator>> (std::istream& os, Date& item);
        bool operator> (const Date& other) const noexcept;
    private:

        int day     = 0;
        int month   = 0;
        int year    = 0;
};
