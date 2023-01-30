#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj, int* &dist, int s) {
  //write your code here
  int n = adj.size();
  queue<int> q;

  q.push(s);
  dist[s] = 0;

  while(!q.empty()) {
    int ind = q.front();
    q.pop();
    int current_layer = (dist[ind] + 1) % 2;
    for (int i = 0; i < adj[ind].size(); i++) {
      int node = adj[ind][i];

      if (dist[node] == -1){
        dist[node] = current_layer;
        q.push(node);
      }
      else {
        if (dist[ind] == dist[node])
          return 0;
      }
    }
  }
  return 1;

}
int bipartite(vector<vector<int> > &adj) {
  int n = adj.size();
  int* dist = new int[n];

  for (int i = 0; i < n; i++) {
    dist[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    if (dist[i] == -1) {
      if (bipartite(adj, dist, i) == 0)
        return 0;
    }
  }
  return 1;
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
  std::cout << bipartite(adj);
}
