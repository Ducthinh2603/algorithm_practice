#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

typedef pair<int, long long> map;
struct comparator {
  bool operator() (
    map const& a,
    map const& b)
    const
  {
    return a.second > b.second;
  }
};

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
  int n = adj.size();
  priority_queue<map, vector<map>, comparator > pq;
  long long* dist = new long long[n];
  bool* visited = new bool[n];
  for (int i = 0; i < n; i++) {
    dist[i] = -1;
    visited[i] = false;
  }
  dist[s] = 0;
  pq.push(std::make_pair(s, 0));
  while(!pq.empty()) {
    map m = pq.top();
    pq.pop();
    int ind = m.first;
    long long d = m.second;
    if (visited[ind]) continue;

    if (ind == t) return d;
    else visited[ind] = true;
    for(int i = 0; i < adj[ind].size(); i++) {
      int temp_ind = adj[ind][i];
      long long c = cost[ind][i];
      if (!visited[temp_ind]) {
        if (dist[temp_ind] == -1 || dist[temp_ind] > d + c) {
          dist[temp_ind] = d + c;
          pq.push(std::make_pair(temp_ind, dist[temp_ind]));
        }
      }
    }
  }
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
