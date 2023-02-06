package utils.java;
import java.util.*;

public class DisjointSet {
    class DisjointSetElement {
        int parent;
        int rank;

        DisjointSetElement() {
            rank = 0;
            parent = -1;
        }

    }
    int n;
    List<DisjointSetElement> sets;
    DisjointSet(int n) {
        this.n = n;
        sets = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            sets.set(i, new DisjointSetElement());
        }
    }
    public int getParent(int node) {
        if(sets.get(node).parent != -1) {
            sets.get(node).parent = getParent(sets.get(node).parent);
        }
        return node;
    }
    public void merge(int destination, int source) {
        int realDestination = getParent(destination);
        int realSource = getParent(source);
        if (realDestination != realSource) {
            int des = realDestination;
            int src = realSource;
            if (sets.get(realDestination).rank == sets.get(realSource).rank) {
                sets.get(realSource).rank += 1;
            }
            else if (sets.get(realDestination).rank > sets.get(realSource).rank) {
                des = realSource;
                src = realDestination;
            }
            sets.get(des).parent = src;
        }
        
    }
}

// Example for min Heap
class Pair<T, R> {
    T first;
    R second;
    public Pair(T x, R y) {
        first = x;
        second = y;
    }
    Comparator<Pair<Integer, Long>> comparator = new Comparator<Pair<Integer,Long>>() {
        @Override
        public int compare(Pair<Integer, Long> a, Pair<Integer, Long> b){
            if (a.second > b.second) return 1;
            else if (a.second < b.second) return -1;
            else return 0;
        }
    };
    PriorityQueue<Pair<Integer, Long>> pQueue = new PriorityQueue<>(1, comparator);
}

