#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <fstream>
#include <algorithm>

using namespace std;

const string PATH_BD   = "1.txt";

struct Item;
class Stock;

ostream& operator<< (ostream& os, const Item& item);
ostream& operator<< (ostream& os, const Stock& stock);

struct Item final {
    Item(const string& t_fam, const double& t_price, const int& t_quant, const int& t_num)
        : fam(t_fam)
        , price(t_price)
        , quant(t_quant)
        , num(t_num)
    {}

    string fam;
    double price;
    int    quant;
    int    num;
};

class Stock final {
    friend ostream& operator<< (ostream& os, const Stock& stock);

    public:
        template<typename... Args>
        void addItem(Args... args) noexcept {
            m_store.emplace_back(args...);
        }

        void ls() const noexcept {
            Stock::printHeader();
            for (const auto& i : m_store) {
                cout << i << endl;
            }
            Stock::printFooter(m_store.size());
        }

        void searchNumAndPrint(const int& num) const noexcept {
            size_t numNum = 0;

            Stock::printHeader();
            for (const auto& i : m_store) {
                if (i.num == num) {
                    cout << i << endl;
                    ++numNum;
                }
            }
            Stock::printFooter(numNum);
        }

        void sortOnQuant() noexcept {
            sort(m_store.begin(), m_store.end(), [](const auto& a, const auto& b){
                return (a.quant < b.quant);
            });
        }

        void searchFamAndPrint(const string& fam) const noexcept {
            size_t num     = 0;
            double procent = 0;

            double dist;
            double maxLen;
            double curProcent;
            string curFam;

            for (size_t i = 0; i < m_store.size(); ++i) {
                curFam     = m_store[i].fam;
                dist       = static_cast<double>(Lev_distantion(fam.size(), curFam.size(), fam, curFam));
                maxLen     = static_cast<double>(max(fam.size(), curFam.size()));
                curProcent = (maxLen - dist) / maxLen * 100;

                if (curProcent > procent) {
                    procent = curProcent;
                    num = i;
                }
            }

            Stock::printHeader();
            cout << m_store[num] << endl;
            cout << "procent\t\t" << procent << endl;
            Stock::printFooter(1);
        }

        static void printHeader() noexcept
        {
            cout << endl << "fam" << "\t\t\t" << "price" << "\t\t\t" << "quant" << "\t\t\t" << "num" << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
        }

        static void printFooter(const size_t& total) noexcept
        {
            cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "total\t\t" << total << endl << endl;
        }

    private:
        vector<Item> m_store;

        int Lev_distantion(const int i, const int j, const string& a, const string& b) const noexcept {
            // Wagner–Fischer algorithm
            if (min(i, j) == 0) {
                return max(i, j);
            } else {
                return min(
                    Lev_distantion(i-1, j, a, b) + 1,
                    min(
                        Lev_distantion(i, j - 1, a, b) + 1,
                        Lev_distantion(i - 1, j - 1, a, b) + (a[i - 1] == b[j - 1] ? 0 : 1)
                    )
                );
            }
        }
};

int main() {
    Stock a;

    int code;
    string fam;
    double price;
    int quant;
    int num;

    fstream fs;
    fs.open(PATH_BD, fstream::in | fstream::out);

    if (fs.is_open()) {
        while (true) {
            fs  >> fam >> price >> quant >> num;
            if (fs.eof()) {
                break;
            }
            a.addItem(fam, price, quant, num);
        }

        fs.close();
        fs.open(PATH_BD, fstream::in | fstream::out | ofstream::trunc);

        do {
            cout << "add to back\t1\n";
            cout << "findQuant\t3\n";
            cout << "ls\t\t6\n";
            cout << "searchFam\t7\n";
            cout << "sortOnQuant\t8\n";
            cout << "exit\t\t0\n\n";
            cout << "code:\t";
            cin  >> code;

            if (code == 1) {
                cout << "enter info: fam(s) price(d) quant(i) num(i)\n";
                cin  >> fam >> price >> quant >> num;
                a.addItem(fam, price, quant, num);
            } else if (code == 6) {
                a.ls();
            } else if (code == 3) {
                cout << "enter num: num(i)\n";
                cin  >> num;

                a.searchNumAndPrint(num);
            } else if (code == 7) {
                cout << "enter fam: fam(s)\n";
                cin  >> fam;

                a.searchFamAndPrint(fam);
            } else if (code == 8) {
                a.sortOnQuant();
                a.ls();
            }
        } while (code);

        fs << a;
    } else {
        cout << "Error with 1.txt" << endl;
    }

    fs.close();
    cout << "----------EXIT----------" << endl;
    return 0;
}

ostream& operator<< (ostream& os, const Item& item) {
    os << item.fam << "\t\t\t" << item.price << "\t\t\t" << item.quant << "\t\t\t" << item.num << endl;
    return (os);
}

ostream& operator<< (ostream& os, const Stock& stock) {
    for (const auto& i : stock.m_store) {
        os << i << endl;
    }
    return os;
}
