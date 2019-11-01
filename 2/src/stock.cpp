#include <iostream>
#include <algorithm>
#include <vector>
#include <cstddef>
#include <string>

#include "stock.hpp"
#include "storage.hpp"

std::ostream& operator<< (std::ostream& os, const Stock& stock) {
    for (const auto& i : stock.m_store) {
        os << i << std::endl;
    }
    return os;
}

void Stock::ls() const noexcept {
    Stock::printHeader();
    for (const auto& i : m_store) {
        std::cout << i << std::endl;
    }
    Stock::printFooter(m_store.size());
}

void Stock::searchNumAndPrint(const int num) const noexcept {
    size_t numNum = 0;

    Stock::printHeader();
    for (const auto& i : m_store) {
        if (i.num == num) {
            std::cout << i << std::endl;
            ++numNum;
        }
    }
    Stock::printFooter(numNum);
}

void Stock::sortOnQuant() noexcept {
    sort(m_store.begin(), m_store.end(), [](const auto& a, const auto& b){
        return (a.quant < b.quant);
    });
}

void Stock::searchFamAndPrint(std::string_view fam) const noexcept {
    size_t num     = 0;
    double procent = 0;

    double dist;
    double maxLen;
    double curProcent;
    std::string curFam;

    for (size_t i = 0; i < m_store.size(); ++i) {
        curFam     = m_store[i].fam;
        dist       = static_cast<double>(Lev_distantion(fam.size(), curFam.size(), fam, curFam));
        maxLen     = static_cast<double>(std::max(fam.size(), curFam.size()));
        curProcent = (maxLen - dist) / maxLen * 100;

        if (curProcent > procent) {
            procent = curProcent;
            num = i;
        }
    }

    Stock::printHeader();
    std::cout << m_store[num] << std::endl;
    std::cout << "procent\t\t" << procent << std::endl;
    Stock::printFooter(1);
}

void Stock::printHeader() noexcept {
    std::cout << std::endl << "fam" << "\t\t\t" << "price" << "\t\t\t" << "quant" << "\t\t\t" << "num" << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------------------------" << std::endl;
}

void Stock::printFooter(const size_t total) noexcept {
    std::cout << "------------------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "total\t\t" << total << std::endl << std::endl;
}

int Stock::Lev_distantion(const int i, const int j, std::string_view a, std::string_view b) const noexcept {
    if (std::min(i, j) == 0) {
        return std::max(i, j);
    } else {
        return std::min({
            Lev_distantion(i-1, j, a, b) + 1,
            Lev_distantion(i, j - 1, a, b) + 1,
            Lev_distantion(i - 1, j - 1, a, b) + (a[i - 1] == b[j - 1] ? 0 : 1)
        });
    }
}
