import java.util.*;

public class LCS2 {

    private static void printRs(int[][] rs, int[] s, int[] t) {
        int n = s.length, m = t.length;
        System.out.print("  ");
        for (int k : t) {
            System.out.print(k + " ");
        }
        System.out.println();
        for (int i = 0; i < n; i++) {
            System.out.print(s[i] + " ");
            for (int j = 0; j < m; j++) {
                System.out.print(rs[i][j] + " ");
            }
            System.out.println();
        }
    }

    private static int lcs2(int[] a, int[] b) {
        //Write your code here
        int n = a.length, m = b.length;
        int[][] rs = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                boolean check = a[i] == b[j];
                if (i == 0 && j == 0) {
                    rs[i][j] = check ? 1 : 0;
                } else {
                    int temp = 0;
                    if (i >= 1 && j >= 1) temp = Math.max(temp, rs[i - 1][j - 1]);
                    if (i >= 1) temp = Math.max(temp, rs[i - 1][j]);
                    if (j >= 1) temp = Math.max(temp, rs[i][j - 1]);
                    rs[i][j] = check ? temp + 1 : temp;
                }
            }
        }
//        printRs(rs, a, b);
        return rs[n - 1][m - 1];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        int m = scanner.nextInt();
        int[] b = new int[m];
        for (int i = 0; i < m; i++) {
            b[i] = scanner.nextInt();
        }
//        int[] a = new int[] {2, 7, 5};
//        int[] b = new int[] {2, 5};

        System.out.println(lcs2(a, b));
    }
}

