#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void print(vector<long long> distance) {
  for (int i = 0; i < distance.size(); i++) {
    std::cout<< distance[i] << " ";
  }
  std::cout<< "\n";
}

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
  long long INF = std::numeric_limits<long long>::max();
  int n = adj.size();
  distance[s] = 0;
  for(int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < adj[j].size(); k++) {
        int t = adj[j][k];
        long long c = cost[j][k];
        if (distance[j] != INF && distance[t] > distance[j] + c) {
          distance[t] = distance[j] + c;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (distance[i] != INF) {
      reachable[i] = 1;
    }
  }
  for(int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < adj[j].size(); k++) {
        int t = adj[j][k];
        long long c = cost[j][k];
        if (distance[j] != INF && distance[t] > distance[j] + c) {
          distance[t] = distance[j] + c;
          shortest[t] = 0;
        }
      }
    }
  }
}


int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
