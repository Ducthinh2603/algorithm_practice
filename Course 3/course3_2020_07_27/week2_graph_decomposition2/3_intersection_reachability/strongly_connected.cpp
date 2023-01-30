#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

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

void explore(int ind, vector<vector<int> >& adj, bool* visited, vector<int> &order) {
  
  visited[ind] = true;
  int m = adj[ind].size();
  if (m == 0) {
    order.push_back(ind);
    return;
  }
  else {
    for (int i = 0; i < m; i++) {
      if (!visited[adj[ind][i]])
        explore(adj[ind][i], adj, visited, order);
    }
    order.push_back(ind);
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
vector<vector<int> > get_reverse_graph(vector<vector<int> > adj) {
  int n = adj.size();
  vector<vector<int> > rev(n, vector<int>());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      rev[adj[i][j]].push_back(i);
    }
  }
  return rev;
}

void show_order(vector<int> order) {
  for (int i = 0; i <= order.size() - 1; i++) {
    std::cout << order[i] + 1 << " ";
  }
  std::cout << "\n";
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  int n = adj.size();
  vector<vector<int> > rev = get_reverse_graph(adj);
  vector<int> order = toposort(rev);

  // show_order(order);

  bool* removed = new bool[n];
  bool* visited = new bool[n];
  for (int i = 0; i < n; i++) {
    removed[i] = false;
    visited[i] = false;
  }

  for (int i = order.size() - 1; i >=0; i--) {
    if (!visited[order[i]] && !removed[order[i]]) {
      explore(order[i], adj, visited, removed);
      result++;
    }
  }
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
