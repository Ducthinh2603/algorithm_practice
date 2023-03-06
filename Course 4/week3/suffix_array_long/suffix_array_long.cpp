#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;

void counting_sort(vector<int>& p, vector<int>& c, int k)
{
  int n = p.size();
  vector<int> cnt(n);
  vector<int> pos(n);
  vector<int> p_new(n);
  vector<int> c_new(n);
  for (auto x: c){
    cnt[x]++;
  }
  pos[0] = 0;
  for (int i = 1; i < n; i++) {
    pos[i] = pos[i - 1] + cnt[i - 1];
  }
  for (auto x: p) {
    p_new[pos[c[x]]] = x;
    pos[c[x]]++;
  }
  p = p_new;

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

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
vector<int> BuildSuffixArray(const string &text)
{
  // vector<int> result;
  // Implement this function yourself
  int n = text.size();
  vector<pair<char, int>> arr(n);
  vector<int> p(n);
  vector<int> c(n);

  // first implementation
  for (int i = 0; i < n; i++)
  {
    arr[i] = {text[i], i};
  }
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n; i++)
  {
    p[i] = arr[i].second;
  }
  c[p[0]] = 0;
  for (int i = 1; i < n; i++)
  {
    if (arr[i].first != arr[i - 1].first)
    {
      c[p[i]] = c[p[i - 1]] + 1;
    }
    else
    {
      c[p[i]] = c[p[i - 1]];
    }
  }

  int k = 1;
  while (k < n)
  {
    for (int i = 0; i < n; i++) {
      p[i] = (p[i] - k + n) % n;
    } 
    counting_sort(p, c, k);
    k = 2 * k;
  }
  return p;
}

int main()
{
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i)
  {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
