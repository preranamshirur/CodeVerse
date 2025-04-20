#include <stdbool.h>

bool isValid(char* s) {
    char stack[10000];
    int top = -1;

    for (int i = 0; s[i]; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        }

        else {
            if (top == -1)
                return false;
            char last = stack[top--];
            if ((c == ')' && last != '(') || (c == '}' && last != '{') ||
                (c == ']' && last != '[')) {
                return false;
            }
        }
    }

    return top == -1;
}
