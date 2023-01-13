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

int number_of_components(vector<vector<int> > &adj) {
  int rs = 0;
  int n = adj.size();
  bool* visited = new bool[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }
  vector<int> stack;
  
  while(true) {
    if (stack.empty()) {
      int unvisited_ind = get_unvisited(visited, n);
      if (unvisited_ind == -1) break;
      stack.push_back(unvisited_ind);
      rs += 1;
    } 
    else {
      int ind = stack.back();
      stack.pop_back();

      visited[ind] = true;
      int m = adj[ind].size();
      for (int i = 0; i < m; i++) {
        int temp = adj[ind][i];
        if (!visited[temp]) {
          stack.push_back(temp);
        }
      }
    }
  }

  return rs;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
