#pragma once

#include <vector>
#include <iostream>

#include "theme.h"

using store_theme = std::vector<Theme>;
std::ostream& operator<<(std::ostream& os, const store_theme& d);

class Company {
public:
    Company() = default;

    int add_theme(const Theme& t);
    store_theme find_developer(std::string developer);
    store_theme find_group(int group);
    void write_date(size_t id, int date);
    // void sort();

	friend std::ostream& operator<< (std::ostream& os, const Company& cp);

private:
    store_theme m_store;
};
