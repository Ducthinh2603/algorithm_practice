import java.util.*;
import java.io.*;

public class StackWithMax {
    class FastScanner {
        StringTokenizer tok = new StringTokenizer("");
        BufferedReader in;

        FastScanner() {
            in = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() throws IOException {
            while (!tok.hasMoreElements())
                tok = new StringTokenizer(in.readLine());
            return tok.nextToken();
        }
        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }

    static class MyStack{
        Stack<Integer> mainStack = new Stack<>();
        Stack<Integer> auxiliaryStack = new Stack<>();

        public void push(Integer item) {
            if (mainStack.isEmpty()) {
                auxiliaryStack.push(item);
            }
            else {
                int current = auxiliaryStack.peek();
                int tempMin = current < item? item: current;
                auxiliaryStack.push(tempMin);
            }
            mainStack.push(item);
        }

        public Optional<Integer> pop() {
            if (mainStack.isEmpty()) {
                return Optional.empty();
            }
            else {
                auxiliaryStack.pop();
                Integer item = mainStack.pop();
                return Optional.of(item);
            }
        }

        public Optional<Integer> max(){
            return auxiliaryStack.isEmpty()? Optional.empty(): Optional.of(auxiliaryStack.peek());
        }
    }

    public void solve() throws IOException {
        FastScanner scanner = new FastScanner();
        int queries = scanner.nextInt();
        MyStack stack = new MyStack();
        List<Integer> rs = new ArrayList<>();

        for (int qi = 0; qi < queries; ++qi) {
            String operation = scanner.next();
            if ("push".equals(operation)) {
                int value = scanner.nextInt();
                stack.push(value);
            } else if ("pop".equals(operation)) {
                stack.pop();
            } else if ("max".equals(operation)) {
                rs.add(stack.max().orElse(-1));
            }
        }
        rs.forEach(System.out::println);

    }

    static public void main(String[] args) throws IOException {
        new StackWithMax().solve();
    }
}
