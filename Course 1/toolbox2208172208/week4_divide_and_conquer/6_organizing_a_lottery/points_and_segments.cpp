#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
  vector<pair<int, int>>pnts, segs;

  // contruct and sort segs desc
  for (int i = 0; i < starts.size(); i++) {
    segs.push_back({starts[i], 1});
    segs.push_back({ends[i] + 1, -1});
  }
  std::sort(segs.begin(), segs.end(), std::greater<pair<int,int>>());

  // attach points with ind, sort asc
  for (int i = 0; i < points.size(); i++) {
    pnts.push_back({points[i], i});
  }
  std::sort(pnts.begin(), pnts.end());

  // loop through points
  int count = 0;
  for (int i = 0; i < pnts.size(); i++) {
    int x = pnts[i].first;
    while(!segs.empty() && segs.back().first <= x) {
      count += segs.back().second;
      segs.pop_back();
    }
    cnt[pnts[i].second] = count;
  }

  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
