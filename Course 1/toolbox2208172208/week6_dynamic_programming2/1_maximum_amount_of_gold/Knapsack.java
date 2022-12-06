import java.util.*;

public class Knapsack {
    static int optimalWeight(int W, int[] w) {
        //write you code here
        int result = 0;
        for (int i = 0; i < w.length; i++) {
          if (result + w[i] <= W) {
            result += w[i];
          }
        }
        return result;
    }

    static int optimalGold(int W, int[] w) {
        int n = w.length;
        int[][] track = new int[n + 1][W + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= W; j++) {
                track[i][j] = track[i - 1][j];
                if (j - w[i - 1] >= 0) {
                    track[i][j] = Math.max(track[i][j], track[i - 1][j - w[i - 1]] + w[i - 1]);
                }
            }
        }

        return track[n][W];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int W, n;
        W = scanner.nextInt();
        n = scanner.nextInt();
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = scanner.nextInt();
        }
//        System.out.println(optimalWeight(W, w));
        System.out.println(optimalGold(W, w));
    }
}

