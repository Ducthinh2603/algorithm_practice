#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
  //write your code here
} 
int get_unvisited(bool* visited, int n) {
  for (int i = 0; i < n; i++) {
    if (!visited[i]) return i;
  }
  return -1;
}

void explore(int ind, vector<vector<int> >& adj, bool* visited, vector<int> &order) {
  
  visited[ind] = true;
  int m = adj[ind].size();
  if (m == 0) {
    order.insert(order.begin(), ind);
    return;
  }
  else {
    for (int i = 0; i < m; i++) {
      if (!visited[adj[ind][i]])
        explore(adj[ind][i], adj, visited, order);
    }
    order.insert(order.begin(), ind);
    return;
  }
}    

vector<int> toposort(vector<vector<int> > adj) {
  int n = adj.size();
  vector<int> order;
  //write your code here
  bool* visited = new bool[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }
  for (int i = 0; i < n; i++) {
    if (!visited[i])
      explore(i, adj, visited, order);    
  }
  return order;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
