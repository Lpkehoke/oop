#include <iostream>
#include <string>
#include <fstream>

#include "stock.hpp"
#include "storage.hpp"
#include "date.hpp"

const std::string PATH_BD = "1.txt";

int main() {
    Stock a;

    int         code;
    std::string fam;
    double      price;
    int         quant;
    int         num;
    Date        date;

    std::fstream fs;
    fs.open(PATH_BD, std::fstream::in | std::fstream::out);

    if (fs.is_open()) {
        while (true) {
            fs  >> fam >> price >> quant >> num >> date;
            if (fs.eof()) {
                break;
            }
            a.addItem(fam, price, quant, num, date);
        }

        fs.close();
        fs.open(PATH_BD, std::fstream::in | std::fstream::out | std::ofstream::trunc);

        do {
            std::cout << "add to back\t1\n";
            std::cout << "Find on date\t2\n";
            std::cout << "findNum\t\t3\n";
            std::cout << "ls\t\t6\n";
            std::cout << "searchFam\t7\n";
            std::cout << "sortOnQuant\t8\n";
            std::cout << "exit\t\t0\n\n";
            std::cout << "code:\t";
            std::cin  >> code;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				std::cout << "incorect input" << std::endl;
				code = 6;
			}

            if (code == 1) {
                std::cout << "enter info: fam(s) price(d) quant(i) num(i) year(i) month(i) day(i)\n";
				while (true) {
					std::cin  >> fam >> price >> quant >> num >> date;
					if (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(std::cin.rdbuf()->in_avail());
						std::cout << "incorect input" << std::endl;
					} else {
						break;
					}
				}
                a.addItem(fam, price, quant, num, date);
            } else if (code == 6) {
                a.ls();
            } else if (code == 3) {
                std::cout << "enter num: num(i)\n";
				while (true) {
					std::cin  >> num;
					if (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(std::cin.rdbuf()->in_avail());
						std::cout << "incorect input" << std::endl;
					} else {
						break;
					}
				}

                a.searchNumAndPrint(num);
            } else if (code == 7) {
                std::cout << "enter fam: fam(s)\n";
				while (true) {
					std::cin  >> fam;
					if (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(std::cin.rdbuf()->in_avail());
						std::cout << "incorect input" << std::endl;
					} else {
						break;
					}
				}

                a.searchFamAndPrint(fam);
            } else if (code == 8) {
                a.sortOnQuant();
                a.ls();
            } else if (code == 2) {
                std::cout << "enter info: year(i) month(i) day(i)\n";
				while (true) {
					std::cin >> date;
					if (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(std::cin.rdbuf()->in_avail());
						std::cout << "incorect input" << std::endl;
					} else {
						break;
					}
				}
                a.changeShelLife(date);
            }
        } while (code);

        fs << a;
    } else {
        std::cout << "Error with 1.txt" << std::endl;
    }

    fs.close();
    std::cout << "----------EXIT----------" << std::endl;
    return 0;
}
