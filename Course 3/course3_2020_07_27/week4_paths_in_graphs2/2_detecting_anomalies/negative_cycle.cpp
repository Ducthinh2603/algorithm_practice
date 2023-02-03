#include <iostream>
#include <vector>

#define INF 100000001

using std::vector;

bool is_negative_cycle(int src, long long* dist, vector<vector<int> > &adj, vector<vector<int> > &cost)
{
  int n = adj.size();
  for (int i = 0; i < n; i++)
  {
    dist[i] = INF;
  }
  dist[src] = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int s = 0; s < n; s++)
    {
      for (int k = 0; k < adj[s].size(); k++)
      {
        int t = adj[s][k];
        long long c = cost[s][k];
        if (dist[s] != INF && dist[t] > dist[s] + c)
        {
          dist[t] = dist[s] + c;
        }
      }
    }
  }
  for (int s = 0; s < n; s++)
  {
    for (int k = 0; k < adj[s].size(); k++)
    {
      int t = adj[s][k];
      long long c = cost[s][k];
      if (dist[s] != INF && dist[t] > dist[s] + c)
      {
        return true;
      }
    }
  }
  return false;
}

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost)
{
  // write your code
  int n = adj.size();
  long long* dist = new long long[n];
  bool* visited = new bool[n];
  for(int i = 0; i < n; i++) {
    visited[i] = false;
  }
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      if (is_negative_cycle(i, dist, adj, cost)) return true;
    }
    for (int i = 0; i < n; i++) {
      if (dist[i] != INF) {
        visited[i] = true;
      }
    }
  }
  return 0;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
