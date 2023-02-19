#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

class Trie {
public:
    trie build_trie(vector<string> & patterns) {
        trie t(1, edges());
        int current_num = 1;
        // write your code here
        for (const auto & p : patterns) {
            int next_ind = 0;
            for (const auto & c : p) {
                if (t[next_ind].count(c)) {
                    next_ind = t[next_ind][c];
                } else {
                    t[next_ind][c] = current_num;
                    next_ind = current_num;
                    t.push_back(edges());
                    current_num++;
                }
            }
        }
        return t;
    }

    trie build_trie(string& text) {
        trie t(1, edges());
        int current_num = 1;
        int n = text.size();
        vector<string> patterns;

        for (int i = 0; i < n; i++) {
            patterns.push_back(text.substr(i, n - i));
        }
        return build_trie(patterns);
    }
};
