#include <iostream>
#include <string>
#include <fstream>

#include "storage.hpp"
#include "stock.hpp"

const std::string PATH_BD = "1.txt";

int main() {
    Stock a;

    int         code;
    std::string fam;
    double      price;
    int         quant;
    int         num;

    std::fstream fs;
    fs.open(PATH_BD, std::fstream::in | std::fstream::out);

    if (fs.is_open()) {
        while (true) {
            fs  >> fam >> price >> quant >> num;
            if (fs.eof()) {
                break;
            }
            a.addItem(fam, price, quant, num);
        }

        fs.close();
        fs.open(PATH_BD, std::fstream::in | std::fstream::out | std::ofstream::trunc);

        do {
            std::cout << "add to back\t1\n";
            std::cout << "findQuant\t3\n";
            std::cout << "ls\t\t6\n";
            std::cout << "searchFam\t7\n";
            std::cout << "sortOnQuant\t8\n";
            std::cout << "exit\t\t0\n\n";
            std::cout << "code:\t";
            std::cin  >> code;

            if (code == 1) {
                std::cout << "enter info: fam(s) price(d) quant(i) num(i)\n";
                std::cin  >> fam >> price >> quant >> num;
                a.addItem(fam, price, quant, num);
            } else if (code == 6) {
                a.ls();
            } else if (code == 3) {
                std::cout << "enter num: num(i)\n";
                std::cin  >> num;

                a.searchNumAndPrint(num);
            } else if (code == 7) {
                std::cout << "enter fam: fam(s)\n";
                std::cin  >> fam;

                a.searchFamAndPrint(fam);
            } else if (code == 8) {
                a.sortOnQuant();
                a.ls();
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
