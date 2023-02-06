#include <vector>
#include <queue>

using namespace std;


struct DisjointSetsElement {
	int size, parent, rank;
	
	DisjointSetsElement(int size = 0, int parent = -1, int rank = 0):
	    size(size), parent(parent), rank(rank) {}
};

struct DisjointSets {
	int size;
	vector <DisjointSetsElement> sets;

	DisjointSets(int size): size(size), sets(size) {
		for (int i = 0; i < size; i++)
			sets[i].parent = i;
	}

	int getParent(int index) {
		// find parent and compress path
        if (sets[index].parent != -1) {
            sets[index].parent = getParent(sets[index].parent);
        }
        return index;
	}

	void merge(int destination, int source) {
		int realDestination = getParent(destination);
		int realSource = getParent(source);
		if (realDestination != realSource) {
            int src = realSource;
            int des = realDestination;
			if (sets[realDestination].rank == sets[realSource].rank) {
                sets[realDestination].rank++;
            }
            else if(sets[realDestination].rank > sets[realSource].rank) {
                src = realDestination;
                des = realSource;
            }
            sets[des].parent = src;

		}		
	}
};

// An Example for min Heap
typedef pair<int, long long> map;
struct comparator {
  bool operator() (
    map const& a,
    map const& b)
    const
  {
    return a.second > b.second;
  }
};
priority_queue<map, vector<map>, comparator > pq;