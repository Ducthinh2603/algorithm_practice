#include <iostream>
#include <vector>

using std::vector;
using std::pair;


int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  int rs = 0;
  int n = adj.size();
  bool* visited = new bool[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }
  vector<int> stack;
  stack.push_back(x);
  while(rs == 0 && !stack.empty()) {
    int ind = stack.back();
    stack.pop_back();

    visited[ind] = true;
    int m = adj[ind].size();
    for (int i = 0; i < m; i++) {
      int temp = adj[ind][i];
      if (temp == y) {
        rs = 1;
        break;
      }
      if (!visited[adj[ind][i]]) {
        stack.push_back(temp);
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
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
