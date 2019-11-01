#pragma once

#include <iostream>
#include <cstddef>
#include <string>
#include <vector>

#include "storage.hpp"

class Stock final {

    public:
        template<typename... Args>
        void addItem(Args... args) noexcept;
        void ls() const noexcept;
        void searchNumAndPrint(const int num) const noexcept;
        void sortOnQuant() noexcept;
        void searchFamAndPrint(std::string_view fam) const noexcept;
        void changeShelLife(const Date& d) noexcept;
        friend std::ostream& operator<< (std::ostream& os, const Stock& stock);

        static void printHeader() noexcept;
        static void printFooter(const std::size_t total) noexcept;

    private:
        int Lev_distantion(const int i, const int j, std::string_view a, std::string_view b) const noexcept;

        std::vector<Storage> m_store;
};

template<typename... Args>
void Stock::addItem(Args... args) noexcept {
    m_store.emplace_back(args...);
}
