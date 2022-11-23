#include <iostream>
#include <vector>
#include <cmath>
using std::vector;

vector<int> optimal_summands(int n) {
  int k = ceil(sqrt(2 * n)) - 1;
  int temp = n - (k * (k + 1) / 2);
  while (temp <= k) {
    temp += k;
    k--;
  }
  vector<int> summands;
  for (int i = 1; i <=k; i++) {
    summands.push_back(i);
  }
  summands.push_back(temp);
  //write your code here
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
