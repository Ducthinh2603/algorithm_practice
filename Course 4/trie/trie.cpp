#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

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

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}