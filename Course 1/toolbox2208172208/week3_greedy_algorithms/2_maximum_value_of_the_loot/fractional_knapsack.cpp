#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();
  vector<pair<double, int>> profit(n);
  for (int i = 0; i < n; i++) {
    profit.push_back({(double)(values[i])/weights[i], i});
  }
  std::sort(profit.begin(), profit.end());
  while(capacity > 0 && !profit.empty()) {
    pair<double, int> item = profit.back();
    profit.pop_back();
    int w = std::min(weights[item.second], capacity);
    value += w * item.first;
    capacity -= w;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
