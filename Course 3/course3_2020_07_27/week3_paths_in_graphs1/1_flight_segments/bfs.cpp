#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  int n = adj.size();
  int rs = -1;

  queue<int> q;
  bool* visited = new bool[n]; 
  int* dist = new int[n];

  for (int i = 0; i < n; i++) {
    visited[i] = false;
    dist[i] = -1;
  }

  q.push(s);
  visited[s] = true;
  dist[s] = 0;

  while(!q.empty() && rs == -1) {
    int ind = q.front();
    q.pop();
    int current_layer = dist[ind] + 1;
    for (int i = 0; i < adj[ind].size(); i++) {
      int node = adj[ind][i];
      if (node == t){
        rs = current_layer;
        break;
      }

      if (!visited[node]){
        dist[node] = current_layer;
        q.push(node);
        visited[node] = true;
      }
    }
  }
  return rs;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
