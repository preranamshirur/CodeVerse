import java.util.Stack;

class MyQueue {

    Stack<Integer> s1;
    Stack<Integer> s2;

    public MyQueue() {
        s1 = new Stack<>();
        s2 = new Stack<>();
    }
    
    public void push(int x) {
        s1.push(x);
    }
    
    public int pop() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }
        if (!s2.isEmpty()) {
            return s2.pop();
        }
        return -1;
    }
    
    public int peek() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }
        if (!s2.isEmpty()) {
            return s2.peek();
        }
        return -1;
    }
    
    public boolean empty() {
        return s1.isEmpty() && s2.isEmpty();
    }
}
