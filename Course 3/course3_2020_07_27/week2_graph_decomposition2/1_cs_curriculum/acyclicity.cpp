#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int get_unvisited(bool* visited, int n) {
  for (int i = 0; i < n; i++) {
    if (!visited[i]) return i;
  }
  return -1;
}

void explore(int ind, vector<vector<int> >& adj, bool* removed, bool* visited) {
  if (visited[ind] || removed[ind]) return;
  visited[ind] = true;
  int m = adj[ind].size();
  if (m == 0) {
    removed[ind] = true;
    return;
  }
  else {
    bool should_removed = true;
    for (int i = 0; i < m; i++) {
      explore(adj[ind][i], adj, removed, visited);
      should_removed &= removed[adj[ind][i]];
    }
    if (should_removed) removed[ind] = true;
    return;
  }
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
  int n = adj.size();
  bool* removed = new bool[n];
  bool* visited = new bool[n];
  for (int i = 0; i < n; i++) {
    removed[i] = false;
    visited[i] = false;
  }
  int ind = get_unvisited(visited, n);
  while (ind != -1) {
    explore(ind, adj, removed, visited);
    ind = get_unvisited(visited, n);
  }
  for (int i = 0; i < n; i++) {
    if (!removed[i]) return 1;
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
