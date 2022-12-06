import java.util.*;

public class LCS3 {
    

    private static int lcs3(int[] a, int[] b, int[] c) {
        //Write your code here
        int m = a.length, n = b.length, l = c.length;
        int[][][] map = new int [m + 1][n + 1][l + 1];

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= l; k++) {
                    int temp = (a[i - 1] == b[j - 1]) && (b[j - 1] == c[k - 1])? map[i - 1][j - 1][k - 1] + 1: map[i - 1][j - 1][k - 1];
                    temp = Math.max(temp, map[i][j][k - 1]);
                    temp = Math.max(temp, map[i][j - 1][k]);
                    map[i][j][k] = Math.max(temp, map[i - 1][j][k]);
                }
            }
        }
        return map[m][n][l];
    }

    public static void main(String[] args) {
        /*
        Remarkable Test case:
Test 1:
        5
8 8 3 1 2
5
8 8 2 1 3
4
5 6 8 1

Test 2:
5
8 3 2 1 7
7
8 2 1 3 8 10 7
6
6 8 3 1 4 7

         */
        Scanner scanner = new Scanner(System.in);
        int an = scanner.nextInt();
        int[] a = new int[an];
        for (int i = 0; i < an; i++) {
            a[i] = scanner.nextInt();
        }
        int bn = scanner.nextInt();
        int[] b = new int[bn];
        for (int i = 0; i < bn; i++) {
            b[i] = scanner.nextInt();
        }
        int cn = scanner.nextInt();
        int[] c = new int[cn];
        for (int i = 0; i < cn; i++) {
            c[i] = scanner.nextInt();
        }
        System.out.println(lcs3(a, b, c));
    }
}

