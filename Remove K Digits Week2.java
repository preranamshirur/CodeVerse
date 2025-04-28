import java.util.Stack;

class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < num.length(); i++) {
            char currentDigit = num.charAt(i);

            while (!stack.isEmpty() && k > 0 && stack.peek() > currentDigit) {
                stack.pop();
                k--;
            }

            stack.push(currentDigit);
        }

        while (k > 0 && !stack.isEmpty()) {
            stack.pop();
            k--;
        }

        StringBuilder result = new StringBuilder();
        while (!stack.isEmpty()) {
            result.insert(0, stack.pop());
        }

        while (result.length() > 0 && result.charAt(0) == '0') {
            result.deleteCharAt(0);
        }

        if (result.length() == 0) {
            return "0";
        }

        return result.toString();
    }
}
