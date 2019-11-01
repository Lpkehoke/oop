#pragma once

#include <iostream>
#include <cstddef>

#include "base_storage.hpp"

class Storage1 : public virtual Base_storage {
    public:
        Storage1(std::string_view t_fam, double t_price, int t_quant, int t_num) noexcept;
		Storage1(const Storage1& other) noexcept;
		Storage1& operator=(const Storage1& other) noexcept;

		virtual ~Storage1() override = default;

		int getNum() const noexcept;
    protected:
		int num;
		static std::size_t count;
};
