#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>

using std::vector;
using std::pair;
using std::priority_queue;
using std::make_pair;

typedef pair<pair<int, int>, double> map;
struct comparator {
  bool operator() (
    map const& a,
    map const& b)
    const
  {
    return a.second > b.second;
  }
};

struct DisjointSetsElement {
	int size, parent, rank;
  pair<int, int> ord;
	
	DisjointSetsElement(int size = 0, int parent = -1, int rank = 0):
	  size(size), parent(parent), rank(rank) {}

  void setOrd(int x, int y) {
    ord = make_pair(x, y);
  }

  int getX() {
    return ord.first;
  }

  int getY() {
    return ord.second;
  }
};

struct DisjointSets {
	int size;
	vector <DisjointSetsElement> sets;
  priority_queue<map, vector<map>, comparator> pq;

	DisjointSets(int size): size(size), sets(size) {
		for (int i = 0; i < size; i++)
			sets[i].parent = i;
	}

	int getParent(int index) {
		// find parent and compress path
        if (sets[index].parent != index) {
            sets[index].parent = getParent(sets[index].parent);
        }
        return sets[index].parent;
	}

  double getDistance(int a, int b) {
    int x1 = sets[a].getX();
    int y1 = sets[a].getY();
    int x2 = sets[b].getX();
    int y2 = sets[b].getY();
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  }

  void print(int a, int b) {
    int x1 = sets[a].getX();
    int y1 = sets[a].getY();
    int x2 = sets[b].getX();
    int y2 = sets[b].getY();
    std::cout << a << ":(" << x1 << ", " << y1 << ") to " << b <<  ":(" << x2 << ", " << y2 << ")\n";
  }

  void makeQueue() {
    for(int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        double dist = getDistance(i, j);
        pq.push(make_pair(make_pair(i, j), dist));
      }
    }
  }

	bool merge(int destination, int source) {
		int realDestination = getParent(destination);
		int realSource = getParent(source);
		if (realDestination != realSource) {
            int src = realSource;
            int des = realDestination;
			if (sets[realDestination].rank == sets[realSource].rank) {
                sets[realSource].rank++;
            }
            else if(sets[realDestination].rank > sets[realSource].rank) {
                src = realDestination;
                des = realSource;
            }
            sets[des].parent = src;
		}	
    else return false;	

    return true;
	}

  double getMinDistance(){
    makeQueue();
    double rs = 0.;
    int num_edges = 0;
    while(num_edges < size - 1) {
      map e = pq.top();
      pq.pop();
      int x = e.first.first, y = e.first.second;
      if (merge(x, y)) {
        num_edges++;
        rs += e.second;
        // print(x, y);
      }
    }
    return rs;
  }
};

double minimum_distance(vector<int> x, vector<int> y) {
  int n = x.size();
  //write your code here
  DisjointSets d_set(n);
  for(int i = 0; i < n; i++) {
    d_set.sets[i].setOrd(x[i], y[i]);
  }
  return d_set.getMinDistance();
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
