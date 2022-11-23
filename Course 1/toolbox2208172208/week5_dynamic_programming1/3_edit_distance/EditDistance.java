import java.util.*;

class EditDistance {

    private static void printRs(int[][] rs, String s, String t) {
        int n = s.length(), m = t.length();
        System.out.print("  ");
        for (int i = 0; i < m; i++) {
            System.out.print(t.charAt(i) + " ");
        }
        System.out.println();
        for (int i = 0; i < n; i++) {
            System.out.print(s.charAt(i) + " ");
            for (int j = 0; j < m; j++) {
                System.out.print(rs[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static int editDistance(String s, String t) {
        //write your code here
        int n = s.length(), m = t.length();
        int[][] rs = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                boolean check = s.charAt(i) == t.charAt(j);
                if (i == 0 && j == 0) {
                    rs[i][j] = check ? 0 : 1;
                } else {
                    int temp = n + m;
                    if (i >= 1 && j >= 1) temp = Math.min(temp, rs[i - 1][j - 1]);
                    if (i >= 1) temp = Math.min(temp, rs[i - 1][j]);
                    if (j >= 1) temp = Math.min(temp, rs[i][j - 1]);
                    rs[i][j] = check ? temp : temp + 1;
                }
            }
        }
//        printRs(rs, s, t);
        return rs[n - 1][m - 1];
    }

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);

        String s = scan.next();
        String t = scan.next();

        System.out.println(editDistance(s, t));
    }

}
