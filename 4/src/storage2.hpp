#pragma once

#include <iostream>
#include <cstddef>

#include "base_storage.hpp"
#include "date.hpp"

class Storage2 : public virtual Base_storage {
    public:
        Storage2(std::string_view t_fam, double t_price, int t_quant, const Date& t_date) noexcept;
		virtual ~Storage2() override = default;

        bool operator> (const Storage2& other) const noexcept;
        bool operator> (const Date& other) const noexcept;

    protected:
		Date date;
};
