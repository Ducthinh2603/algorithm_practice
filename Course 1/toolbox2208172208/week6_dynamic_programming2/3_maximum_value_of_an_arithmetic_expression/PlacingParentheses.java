import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class PlacingParentheses {

    static class Pair {
        long x;
        long y;

        Pair(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    private static void updateTable(Pair temp, long tempVal) {
        if (temp.x > tempVal) temp.x = tempVal;
        if (temp.y < tempVal) temp.y = tempVal;
    }
    private static long getMaximValue(String exp) {
        //write your code here
        List<Character> ops = new ArrayList<>();
        List<Long> nums = new ArrayList<>();
        int m = 0;
        for (int i = 0; i < exp.length(); i++) {
            char c = exp.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                ops.add(c);
                nums.add(Long.parseLong(exp.substring(m, i)));
                m = i + 1;
            }
            if (i == exp.length() - 1) {
                nums.add(Long.parseLong(exp.substring(m)));
            }
        }
//        System.out.println(nums);
//        System.out.println(ops);
        int N = nums.size();
        long[][] minTable = new long[N][N];
        long[][] maxTable = new long[N][N];

        for(int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                int x = j - i, y = j;
                if (i == 0) {
                    minTable[x][y] = nums.get(j);
                    maxTable[x][y] = nums.get(j);
                } else {
                    Pair temp = new Pair(Long.MAX_VALUE, Long.MIN_VALUE);
                    for (int k = 0; k < y - x; k++) {
                        updateTable(temp, eval(minTable[x][x+k], minTable[x + k + 1][y], ops.get(x + k)));
                        updateTable(temp, eval(minTable[x][x+k], maxTable[x + k + 1][y], ops.get(x + k)));
                        updateTable(temp, eval(maxTable[x][x+k], minTable[x + k + 1][y], ops.get(x + k)));
                        updateTable(temp, eval(maxTable[x][x+k], maxTable[x + k + 1][y], ops.get(x + k)));
                    }
                    minTable[x][y] = temp.x;
                    maxTable[x][y] = temp.y;
                }
            }
        }
        return maxTable[0][N - 1];
    }

    private static long eval(long a, long b, char op) {
        if (op == '+') {
            return a + b;
        } else if (op == '-') {
            return a - b;
        } else if (op == '*') {
            return a * b;
        } else {
            assert false;
            return 0;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String exp = scanner.next();
        System.out.println(getMaximValue(exp));
    }
}

