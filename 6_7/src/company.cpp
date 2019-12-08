#include <algorithm>
#include <iostream>

#include "company.h"

int Company::add_theme(const Theme &t) {
    m_store.push_back(t);
	return static_cast<int>(m_store.size() - 1);
}

store_theme Company::find_developer(std::string developer) {
    store_theme a;
    for (const auto& i : m_store) {
        if (i.developer == developer) {
            a.push_back(i);
        }
    }

    if (a.size() != 0) {
        return a;
    } else {
        throw std::string("error developer is ghost");
    }
}

store_theme Company::find_group(int group) {
    store_theme a;
    for (const auto& i : m_store) {
        if (i.group == group) {
            a.push_back(i);
        }
    }

    if (a.size() != 0) {
        return a;
    } else {
        throw std::string("error wrong group");
    }
}

void Company::write_date(size_t id, int date) {
	if (m_store.size() > id) {
        m_store[id].date_real = date;
    } else {
        throw std::string("error id");
    }
}

// void Company::sort() {
//     std::sort(m_store.begin(), m_store.end());
// }

std::ostream& operator<< (std::ostream& os, const Company& cp) {
    for (const auto& i : cp.m_store) {
        os << i << std::endl;
    }
    return os;
}

std::ostream& operator<< (std::ostream& os, const store_theme& cp) {
    for (const auto& i : cp) {
        os << i << std::endl;
    }
    return os;
}
