int isOperator(char* token) {
    return (strcmp(token, "+") == 0 ||
            strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 ||
            strcmp(token, "/") == 0);
}

int evalRPN(char** tokens, int tokensSize) {
    int stack[10000];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char* token = tokens[i];

        if (!isOperator(token)) {
            stack[++top] = atoi(token);
        } else {
            int num2 = stack[top--];
            int num1 = stack[top--];
            int result;

            if (strcmp(token, "+") == 0) {
                result = num1 + num2;
            } else if (strcmp(token, "-") == 0) {
                result = num1 - num2;
            } else if (strcmp(token, "*") == 0) {
                result = num1 * num2;
            } else if (strcmp(token, "/") == 0) {
                result = num1 / num2;
            }

            stack[++top] = result;
        }
    }

    return stack[top];
}
