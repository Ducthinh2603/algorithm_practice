#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;

char* inner_inverse_bwt(const string& bwt) {
  int n = bwt.size();
  char* s = new char[n];
  vector<int> pos(n);
  vector<pair<char, int> > a(n);

  int ind;
  for (int i = 0; i < n; i++) {
    if (bwt[i] == '$') ind = i;
    a[i] = {bwt[i], i};
  }
  sort(a.begin(), a.end());

  for (int i = 0; i < n; i++) {
    pos[i] = a[i].second;
  }
  int p = n - 1;
  for (int i = 0; i < n; i++) {
    s[p] = bwt[ind];
    p = (p + n + 1) % n;
    ind = pos[ind];
  }
  return s;
}

string InverseBWT(const string& bwt) {
  string text = inner_inverse_bwt(bwt);

  return text;
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
  return 0;
}
