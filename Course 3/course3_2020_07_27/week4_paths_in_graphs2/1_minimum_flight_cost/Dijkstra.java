import java.util.*;

public class Dijkstra {
    static class Pair<T, R> {
        T first;
        R second;
        public Pair(T x, R y) {
            first = x;
            second = y;
        }
    }
    static Comparator<Pair<Integer, Long>> comparator = new Comparator<Pair<Integer,Long>>() {
        @Override
        public int compare(Pair<Integer, Long> a, Pair<Integer, Long> b){
            if (a.second > b.second) return 1;
            else if (a.second < b.second) return -1;
            else return 0;
        }
    };
    private static long distance(ArrayList<Integer>[] adj, ArrayList<Integer>[] cost, int s, int t) {
        int n = adj.length;
        
        PriorityQueue<Pair<Integer, Long>> pQueue = new PriorityQueue<>(1, comparator);
        long[] dist = new long[n];
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            dist[i] = -1;
            visited[i] = false;
        }
        dist[s] = 0;
        pQueue.add(new Pair<Integer,Long>(s, dist[s]));
        while(!pQueue.isEmpty()) {
            Pair<Integer, Long> e = pQueue.poll();
            int ind = e.first;
            long d = e.second;
            if (visited[ind]) continue;

            if (ind == t) return dist[ind];
            else visited[ind] = true;
            for (int i = 0; i < adj[ind].size(); i++) {
                int temp_ind = adj[ind].get(i);
                long c = cost[ind].get(i);
                if (!visited[temp_ind]) {
                    if (dist[temp_ind] == -1 || dist[temp_ind] > d + c) {
                        dist[temp_ind] = d + c;
                        pQueue.add(new Pair<Integer,Long>(temp_ind, dist[temp_ind]));
                    }
                } 
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        ArrayList<Integer>[] adj = new ArrayList[n];
        ArrayList<Integer>[] cost = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
            cost[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++) {
            int x, y, w;
            x = scanner.nextInt();
            y = scanner.nextInt();
            w = scanner.nextInt();
            adj[x - 1].add(y - 1);
            cost[x - 1].add(w);
        }
        int x = scanner.nextInt() - 1;
        int y = scanner.nextInt() - 1;
        System.out.println(distance(adj, cost, x, y));
        scanner.close();
    }
}

