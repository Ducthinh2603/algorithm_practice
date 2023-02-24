#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::make_pair;
using std::pair;

void count_sort(vector<int> &p, vector<int> &c, int k) {
  int n = p.size();

  // update p
  vector<int> cnt(n);
  for (auto x: c) {
    cnt[x]++;
  }

  vector<int> pos(n);
  pos[0] = 0;
  for (int i = 1; i < n; i++) {
    pos[i] = pos[i - 1] + cnt[i - 1];
  }

  vector<int> p_new(n);
  for (auto x: p) {
    p_new[pos[c[x]]] = x;
    pos[c[x]]++;
  }

  p = p_new;

  // update c
  vector<int> c_new(n);

  c_new[p[0]] = 0;
  for (int i = 1; i < n; i++) {
    if (c[p[i]] == c[p[i - 1]] && c[(p[i] + k) % n] == c[(p[i - 1] + k) % n]){
      c_new[p[i]] = c_new[p[i - 1]];
    }
    else {
      c_new[p[i]] = c_new[p[i - 1]] + 1;
    }
  }

  c = c_new;
}

vector<int> suffix_array(const string &s) {
  int n = s.size();
  vector<int> p(n);
  vector<int> c(n);
  vector<pair<char, int> > a(n);

  // init
  for (int i = 0; i < n; i++) {
    a[i] = make_pair(s[i], i);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    p[i] = a[i].second;
  }
  c[p[0]] = 0;
  for (int i = 1; i < n; i++) {
    if (a[i].first == a[i - 1].first){
      c[p[i]] = c[p[i - 1]];
    }
    else {
      c[p[i]] = c[p[i - 1]] + 1;
    }
  }

  int k = 1;
  while(k < n) {

    for (int i = 0; i < n; i++) {
      p[i] = (p[i] + n - k) % n;
    }

    count_sort(p, c, k);

    k = 2*k;
  }
  return p;
}


string BWT(const string& text) {
  string result = "";
  vector<int> sa = suffix_array(text);
  // write your code here
  int n = text.length();
  for (int i = 0; i < n; i++) {
    result += text[(sa[i] - 1 + n) % n];
  }
  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}