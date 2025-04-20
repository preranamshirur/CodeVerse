#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* simplifyPath(char* path) {
    
    char* stack[3000];
    int top = 0;

    
    char* pathCopy = strdup(path);

    
    char* token = strtok(pathCopy, "/");

    while (token != NULL) {
       
        if (strcmp(token, "..") == 0) {
            if (top > 0) {
                top--;  
            }
        }
        
        else if (strcmp(token, ".") == 0 || strlen(token) == 0) {
           
        }
        
        else {
            stack[top] = token;
            top++;
        }

        token = strtok(NULL, "/");
    }

    if (top == 0) {
        free(pathCopy);
        return strdup("/");
    }

    char* result = (char*)malloc(3000);
    result[0] = '\0';  
    for (int i = 0; i < top; i++) {
        strcat(result, "/");
        strcat(result, stack[i]);
    }

    free(pathCopy);
    return result;
}
