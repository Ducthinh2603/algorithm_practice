package utils.java;
import java.util.*;

public class Pair<T, R> {
    T first;
    R second;

    public Pair(T x, R y) {
        first = x;
        second = y;
    }


    // Example:
    // This comparator is for creating min Heap with PriorityQueue
    static Comparator<Pair<Integer, Long>> comparator = new Comparator<Pair<Integer,Long>>() {
        @Override
        public int compare(Pair<Integer, Long> a, Pair<Integer, Long> b){
            if (a.second > b.second) return 1;
            else if (a.second < b.second) return -1;
            else return 0;
        }
    };
}
