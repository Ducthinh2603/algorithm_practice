#include <iostream>
#include <string>
#include <vector>
#include <math.h>
// #include "../../../../utils/cpp/file_interator.h"

using std::string;
typedef unsigned long long ull;

ull P = 1000000007;
int x = 263;

struct Data {
    string pattern, text;
};

// Data read_input(string fileName) {
//     Data data;
//     FileInteractor file = FileInteractor(fileName);
//     vector<string> contents = file.readLines()->getContents();
//     data.pattern = contents[0];
//     data.text = contents[1];
//     return data;
// }

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

ull hash_function(string a) {
    ull hash = 0;
    for (int i = 0; i < a.length(); i++) {
        hash = (hash * x + a[i]) % P;

    }
    return hash;
}

ull* hash_text(string text, int l) {
    ull xtol = 1;
    for (int i = 0; i < l; i++) {
        xtol = (xtol * x) % P;
    }
    int n = text.length();
    ull* rs = new ull[n - l + 1];
    rs[0] = hash_function(text.substr(0, l));
     for (int i = l; i < n; i++) {
        ull hash = hash_function(text.substr(i - l + 1, l));
        rs[i - l + 1] = (rs[i - l] * x + text[i] - (text[i - l] * xtol % P)) % P;
    }
    return rs;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    ull pattern_hash = hash_function(s);
    ull* text_hash = hash_text(t, s.size());

    std::vector<int> ans;
    for (int i = 0; i <= t.size() - s.size(); ++i)
        if (text_hash[i] == pattern_hash && t.substr(i, s.size()) == s)
            ans.push_back(i);
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    string fileName = "D:\\My_project\\Data Structures and Algorithms Specialization\\algorithm_practice\\Course 2\\course2_2003291203\\week3_hash_tables\\3_hash_substring\\tests\\06";
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
