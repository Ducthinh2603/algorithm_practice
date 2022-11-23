#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool my_comparator(string& a, string& b, int n) {
    char x = '0', y = '0';
    int iter = 0;
    while (iter < n) {
        if (a[iter] != b[iter]) {
            x = a[iter];
            y = b[iter];
            break;
        }

        iter++;
    }
    return x < y;
}


bool sort_by_first_digit(string& a, string& b) {
    int na = a.length(), nb = b.length();
    int n = 0;
    string x = "", y = "";
    if (na == nb) {
        x = a;
        y = b;
        n = na;
    }
    else {
        x = a + b;
        y = b + a;
        n = na + nb;
    }
    return my_comparator(x, y, n);
}

string largest_number(vector<string> a) {
    //write your code here
std:sort(a.begin(), a.end(), sort_by_first_digit);
    std::stringstream ret;
    for (int i = a.size() - 1; i >= 0; --i) {
        ret << a[i];
    }
    string result;
    ret >> result;
    return result;
}

int main() {
    int n;
    std::cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    std::cout << largest_number(a);
}
