#pragma once

#include <iostream>
#include <cstddef>

#include "date.hpp"
#include "storage1.hpp"
#include "storage2.hpp"

class Storage final : public Storage1, public Storage2 {
    public:
        Storage(std::string_view t_fam, double t_price, int t_quant, int t_num, const Date& d) noexcept;
		~Storage() override = default;

        void operator! () noexcept;
		virtual void show() const noexcept override;

		friend std::ostream& operator<< (std::ostream& os, const Storage& item);
    private:
        bool shelfLife = true;
};
