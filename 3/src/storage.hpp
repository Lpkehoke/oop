#pragma once

#include <iostream>
#include <cstddef>

#include "date.z"

struct Storage final {
    public:
        explicit Storage(std::string_view t_fam, double t_price, int t_quant, int t_num, const Date& d);
        friend std::ostream& operator<< (std::ostream& os, const Storage& item);
        bool operator> (const Storage& other) const noexcept;
        bool operator> (const Date& other) const noexcept;
        void operator! () noexcept;

        std::string fam;
        double      price;
        int         quant;
        int         num;
        Date        date;

        static std::size_t count;

    private:
        bool shelfLife = true;
};
