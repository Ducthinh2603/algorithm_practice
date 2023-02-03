package utils.java;
import java.util.ArrayList;
import java.util.List;

import utils.java.*;;
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
    int getParent(int node) {
        if(sets.get(node).parent != -1) {
            sets.get(node).parent = getParent(sets.get(node).parent);
        }
        return node;
    }
    void merge(int destination, int source) {
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
