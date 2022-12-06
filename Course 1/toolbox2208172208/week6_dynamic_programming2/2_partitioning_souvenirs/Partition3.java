import java.util.*;
import java.io.*;

public class Partition3 {

    static class Pair {
        int x;
        int y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "(" + x + ", " + y + ")";
        }
    }

    public static boolean subsetSum(int[] S, int n, int a, int b, int c)
    {
        // return true if the subset is found
        if (a == 0 && b == 0 && c == 0) {
            return true;
        }

        // base case: no items left
        if (n < 0) {
            return false;
        }

        // Case 1. The current item becomes part of the first subset
        boolean A = false;
        if (a - S[n] >= 0) {
            A = subsetSum(S, n - 1, a - S[n], b, c);
        }

        // Case 2. The current item becomes part of the second subset
        boolean B = false;
        if (!A && (b - S[n] >= 0)) {
            B = subsetSum(S, n - 1, a, b - S[n], c);
        }

        // Case 3. The current item becomes part of the third subset
        boolean C = false;
        if ((!A && !B) && (c - S[n] >= 0)) {
            C = subsetSum(S, n - 1, a, b, c - S[n]);
        }

        // return true if we get a solution
        return A || B || C;
    }

    private static int isParition(int[] A) {
        int total_weight = Arrays.stream(A).sum();
        if (total_weight % 3 != 0 || A.length < 3) return 0;
        int w = total_weight / 3;
        if (!subsetSum(A, A.length - 1, w, w, w)) return 0;
        return 1;
    }

    private static int partition3(int[] A) {
        //write your code here
        int total_weight = Arrays.stream(A).sum();
        if (total_weight % 3 != 0) return 0;
        else {
            int n = A.length;
            int w = total_weight / 3;
            int[][] map = new int[n + 1][w + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= w; j++) {
                    map[i][j] = map[i - 1][j];
                    if (j >= A[i - 1]) {
                        map[i][j] = Math.max(map[i][j], map[i - 1][j - A[i - 1]] + A[i - 1]);
                    }
                }
            }
            if (map[n][w] == w) {
                Queue<Pair> track = new LinkedList<>();
                boolean[][] count = new boolean[n + 1][w + 1];
                boolean[] mark = new boolean[n];
                for (int i = 0; i < 2; i++) {
                    track.add(new Pair(n, w));
                    int sub_count = 0;
                    count[0][0] = false;
                    while (!track.isEmpty()) {
                        Pair pair = track.poll();
                        int x = pair.x, y = pair.y;
                        if (x >= 1) {
                            if (map[x - 1][y] == map[x][y] && !count[x - 1][y]) {
                                track.add(new Pair(x - 1, y));
                                count[x - 1][y] = true;
                            } else if (y >= A[x - 1] &&
                                    map[x][y] == map[x - 1][y - A[x - 1]] + A[x - 1] &&
                                    !count[x - 1][y - A[x - 1]] &&
                                    !mark[x - 1]
                            ) {
                                track.add(new Pair(x - 1, y - A[x - 1]));
                                count[x - 1][y - A[x - 1]] = true;
                                sub_count += A[x - 1];
                                mark[x - 1] = true;
                                System.out.print(A[x - 1] + " + ");
                            }
                        }
                    }
//                    if (sub_count != w) return 0;
                    System.out.println();
                    System.out.println(sub_count);
                }
                return 1;
            }
            return 0;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
//        System.out.println(partition3(A));
        System.out.println(isParition(A));
    }
}

