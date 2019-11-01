#include <iostream>
#include <cstddef>

#include "base_storage.hpp"

Base_storage::Base_storage(std::string_view t_fam, double t_price, int t_quant) noexcept
    : fam(t_fam)
    , price(t_price)
    , quant(t_quant)
{}

int Base_storage::getQuant() const noexcept {
	return quant;
}

std::string Base_storage::getFam() const noexcept {
	return fam;
}
