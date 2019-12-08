#include <iostream>
#include <vector>
#include <cstddef>
#include <algorithm>
#include <numeric>

using namespace std;

template <typename T>
void tryEnter(T& a) {
    while (true) {
        cin >> a;
        if (cin.fail()) {
			cout << "Repeat pls" << endl;
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
        } else {
            break;
        }
    }
}

template <typename T>
void initializer(vector<T>& a) {
    for (auto& el : a) {
        el = static_cast<T>(static_cast<double>(rand()) * 10. / static_cast<double>(rand()));
    }
}

template <typename T>
T sumChunc(const vector<T>& a) {
    auto minE = min_element(a.begin(), a.end());
    auto maxE = max_element(a.begin(), a.end());

    if (minE < maxE) {
        return accumulate(minE + 1, maxE, static_cast<T>(0));
    } else {
        return accumulate(maxE + 1, minE, static_cast<T>(0));
    }
}

template<typename T>
T sumToMin(const vector<T>& a) {
    return accumulate(a.begin(), min_element(a.begin(), a.end()), static_cast<T>(0));
}

double sumToMin(const vector<double>& a) {
    return accumulate(a.begin(), min_element(a.begin(), a.end()), 0.);
}


int main() {
	std::ios_base::sync_with_stdio(false);
    cout << "Enter size" << endl;
    size_t size;
    tryEnter(size);

    vector<int> a(size);
    vector<double> b(size);
    initializer(a);
    initializer(b);

    for (auto i : a) cout << i << " ";
    cout << endl;
    for (auto i : b) cout << i << " ";
    cout << endl;

    cout << sumChunc(a) << " " << sumChunc(b) << endl;
    cout << sumToMin(a) << " " << sumToMin(b) << endl;

    return 0;
}
