import java.util.*;

public class PrimitiveCalculator {
    private static List<Integer> optimal_sequence(int n) {
        List<Integer> sequence = new ArrayList<Integer>();
        while (n >= 1) {
            sequence.add(n);
            if (n % 3 == 0) {
                n /= 3;
            } else if (n % 2 == 0) {
                n /= 2;
            } else {
                n -= 1;
            }
        }
        Collections.reverse(sequence);
        return sequence;
    }


    private static List<Integer> primitive_calculate(int n) {
        int[] memo = new int[n + 1];
        int[] track = new int[n + 1];

        for (int i = 2; i < n + 1; i++) {
            int a = 1000000;
            int b = 0;
            if (i % 3 == 0) {
                int i_temp = i / 3;
                int temp = memo[i_temp] + 1;
                if (a > temp) {
                    a = temp;
                    b = i_temp;
                }
            }
            if (i % 2 == 0) {
                int i_temp = i / 2;
                int temp = memo[i_temp] + 1;
                if (a > temp) {
                    a = temp;
                    b = i_temp;
                }
            }
            int i_temp = i - 1;
            int temp = memo[i_temp] + 1;
            if (a > temp) {
                a = temp;
                b = i_temp;
            }
            memo[i] = a;
            track[i] = b;
        }

        List<Integer> rs = new ArrayList<>(List.of(n));
        int i = n;
        while (i != 1){
            rs.add(track[i]);
            i = track[i];
        }
        Collections.reverse(rs);
        return rs;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
//        List<Integer> sequence = optimal_sequence(n);
        List<Integer> sequence = primitive_calculate(n);
        System.out.println(sequence.size() - 1);
        for (Integer x : sequence) {
            System.out.print(x + " ");
        }
    }
}

