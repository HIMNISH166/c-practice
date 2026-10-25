#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {

    if (s == NULL) {
        return false;
    }

    char* stack = (char*)malloc((1 + strlen(s)) * sizeof(char));
    if (stack == NULL)return false;

    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }
        else {
            if (top == -1) {
                free(stack);
                return false;
            }

            if ((s[i] == ')' && stack[top] == '(') ||
                (s[i] == '}' && stack[top] == '{') ||
                (s[i] == ']' && stack[top] == '[')) {
                top--;
            }
            else {
                free(stack);
                return false;
            }
        }
    }

    if (top == -1) {
        free(stack);
        return true;
    }
    free(stack);
    return false;
}