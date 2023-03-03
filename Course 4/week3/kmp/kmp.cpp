#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::string;
using std::vector;

void print(vector<int>& arr) {
  for(auto a: arr)
    std::cout << a << " ";
  std::cout << "\n";
}

vector<int> prefixCompute(const string& pattern) {
  int n = pattern.size();
  vector<int> rs(n);
  int border = 0;
  rs[0] = border;
  for (int i = 1; i < n; i++) {
    while(border > 0 && pattern[i] != pattern[border]) {
      border = rs[border - 1];
    }
    if (pattern[i] == pattern[border]) {
      ++border;
    }
    rs[i] = border;
  }
  print(rs);
  return rs;
}

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where 
// the pattern starts in the text.
vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
  // Implement this function yourself
  vector<int> p = prefixCompute(pattern);
  int n = pattern.size();
  int iter = 0;
  for(int i = 0; i < text.size(); i++) {
    if (text[i] == pattern[iter]) {
      if(iter == n - 1) {
        result.push_back(i - n + 1);
        iter = p[iter];
      }
      else {
        iter++;
      }
    }
    else {
      while (iter > 0 && text[i] != pattern[iter]) {
        iter = p[iter - 1];
      }
      if (text[i] == pattern[iter]) {
        iter++;
      }
    }
  }

  return result;
}

int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  print(result);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
