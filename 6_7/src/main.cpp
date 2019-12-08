#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>

#include "company.h"
#include "theme.h"

const std::string PATH_BD = "1.txt";

int main() {
    Company a;
    int code;
    int real_time;
    std::size_t id;
    std::string developer;
    Theme t;
	int group;

    std::fstream fs;
    fs.open(PATH_BD, std::fstream::in | std::fstream::out);

    if (fs.is_open()) {
      while (true) {
           fs >> t;
           if (fs.eof()) {
               break;
           }

           a.add_theme(t);
       }

       fs.close();
       fs.open(PATH_BD, std::fstream::in | std::fstream::out | std::ofstream::trunc);

        do {
            std::cout << "add to back\t1\n";
            std::cout << "add real_time\t2\n";
            std::cout << "find developer\t3\n";
            std::cout << "find group\t4\n";
            std::cout << "ls -la\t\t5\n";
            std::cout << "exit\t\t0\n";

            std::cin >> code;

			try {
				switch(code) {
					case 1:
						std::cout << "enter theme(str, int, str, int)" << std::endl;
						std::cin >> t;
						std::cout << "id: " << (a.add_theme(t)) << std::endl << std::endl;
						break;
					case 2:
						std::cout << "enter id(size_t), real_time(int)" << std::endl;
						std::cin >> id >> real_time;
						a.write_date(id, real_time);
						break;
					case 3:
						std::cout << "enter developer(std::string)" << std::endl;
						std::cin >> developer;
						std::cout << (a.find_developer(developer)) << std::endl;
						break;
					case 4:
						std::cout << "enter group(int)" << std::endl;
						std::cin >> group;
						std::cout << (a.find_group(group)) << std::endl;
						break;
					case 5:
						std::cout << a << std::endl;
						break;
				}
			} catch (const std::string& e) {
				std::cout << e << std::endl;
			} catch ( ... ) {
				std::cout << "smth wrong" << std::endl;
				code = 1;
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());
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
