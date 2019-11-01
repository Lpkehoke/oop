#pragma once

#include <iostream>
#include <cstddef>

#include "date.hpp"

class Storage final {
	public:
	    Storage(std::string_view t_fam, double t_price, int t_quant, int t_num);
		Storage(const Storage& other);
		Storage& operator=(const Storage& other);

	    std::string fam;
	    double      price;
	    int         quant;
	    int         num;
	    Date        date;

	    static std::size_t count;
};

std::ostream& operator<< (std::ostream& os, const Storage& item);
