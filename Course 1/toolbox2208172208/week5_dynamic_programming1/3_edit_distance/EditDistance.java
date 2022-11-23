import java.util.*;

class EditDistance {

    private static void printRs(int[][] rs, String s, String t) {
        int n = s.length(), m = t.length();
        System.out.print("  ");
        for (int i = 1; i <= m; i++) {
            System.out.print(t.charAt(i - 1) + " ");
        }
        System.out.println();
        for (int i = 1; i <= n; i++) {
            System.out.print(s.charAt(i - 1) + " ");
            for (int j = 1; j <= m; j++) {
                System.out.print(rs[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static int editDistance(String s, String t) {
        //write your code here
        int n = s.length(), m = t.length();
        int[][] rs = new int[n + 1][m + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0) {
                    rs[i][j] = j;
                }
                else if (j == 0) {
                    rs[i][j] = i;
                }
                else {
                    int temp = n + m;
                    temp = Math.min(temp, rs[i][j - 1] + 1);
                    temp = Math.min(temp, rs[i - 1][j] + 1);
                    rs[i][j] = s.charAt(i - 1) == t.charAt(j - 1) ? Math.min(temp, rs[i - 1][j - 1]) : Math.min(temp, rs[i - 1][j - 1] + 1);
                }
            }
        }
//        printRs(rs, s, t);
        return rs[n][m];
    }

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);

        String s = scan.next();
        String t = scan.next();

        System.out.println(editDistance(s, t));
    }

}
