#pragma once

#include <iostream>
#include <string>
#include <cstddef>

#include "date.hpp"

class Base_storage {
    public:
		Base_storage(std::string_view t_fam, double t_price, int t_quant) noexcept;
		virtual ~Base_storage() = default;

		virtual void show() const noexcept = 0;
		int getQuant() const noexcept;
		std::string getFam() const noexcept;

	protected:
        std::string fam;
        double      price;
        int         quant;

};
