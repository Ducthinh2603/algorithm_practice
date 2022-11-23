import java.util.*;

public class LCS3 {

    private static void print(int[] x, int y) {
        System.out.print(y + " ");
        for (var i : x) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
    private static void print(int[] x) {
        for (var i: x) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    private static int[] lcs2(int[] x, int[] y) {
        int n = x.length, m = y.length;
        List<Integer> track = new ArrayList<>();
        int[][] map = new int[2][n + 1];

        for (int j = 1; j <= m; j++) {
            for (int i = 0; i <= n; i++) {
                if (i != 0) {
                    int temp = 0;
                    if (x[i - 1] == y[j - 1]) {
                        if (temp < map[(j - 1) % 2][i - 1] + 1) {
                            temp = map[(j - 1) % 2][i - 1] + 1;
                            track.add(i - 1);
                        }
                    }
                    else {
                        temp =Math.max(temp, map[(j - 1) % 2][i - 1]);
                    }
                    temp = Math.max(temp, map[j % 2][i - 1]);
                    map[j % 2][i] = Math.max(temp, map[(j - 1) % 2][i]);
                }
            }
        }
        System.out.println(track);
        int s = track.size();
        int[] rs = new int[s];
        for (int i = 0; i < s; i++) {
            rs[i] = x[track.get(i)];
        }
        return rs;
    }

    private static int lcs3(int[] a, int[] b, int[] c) {
        //Write your code here
        int[] rs = lcs2(a, b);
        System.out.println(Arrays.toString(rs));
        rs = lcs2(rs, c);
        System.out.println(Arrays.toString(rs));
        return rs.length;
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

