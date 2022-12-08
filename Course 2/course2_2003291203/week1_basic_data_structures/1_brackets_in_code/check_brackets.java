import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Stack;

class Bracket {
    Bracket(char type, int position) {
        this.type = type;
        this.position = position;
    }

    boolean match(char c) {
        if (this.type == '[' && c == ']')
            return true;
        if (this.type == '{' && c == '}')
            return true;
        if (this.type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
}

class check_brackets {


    public static void main(String[] args) throws IOException {
        InputStreamReader input_stream = new InputStreamReader(System.in);
        BufferedReader reader = new BufferedReader(input_stream);
        String text = reader.readLine();

        String msg = "Success";

        Stack<Bracket> opening_brackets_stack = new Stack<Bracket>();
        for (int position = 0; position < text.length(); ++position) {
            char next = text.charAt(position);

            if (next == '(' || next == '[' || next == '{') {
                // Process opening bracket, write your code here
                opening_brackets_stack.add(new Bracket(next, position));
            }

            if (next == ')' || next == ']' || next == '}') {
                // Process closing bracket, write your code here
                if (opening_brackets_stack.isEmpty()) {
                    msg = String.valueOf(position + 1);
                    break;
                } else {
                    Bracket bracket = opening_brackets_stack.pop();
                    if (!bracket.match(next)) {
                        msg = String.valueOf(position + 1);
                        break;
                    }
                }
            }
            if (position == text.length() - 1) {
                if (!opening_brackets_stack.isEmpty()) {
                    Bracket bracket = opening_brackets_stack.pop();
                    msg = String.valueOf(bracket.position + 1);
                }
            }
        }
        System.out.println(msg);
        // Printing answer, write your code here
    }
}
