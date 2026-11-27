#include <stdlib.h>
#include <string.h>

char* removeOuterParentheses(char* s) {
    int len = strlen(s);
    // Allocate memory for the result string (+1 for the null terminator)
    char* result = (char*)malloc((len + 1) * sizeof(char));
    
    int depth = 0;
    int j = 0; // Index for the result string
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            // If depth > 0, this '(' is inside a primitive string, so we keep it
            if (depth > 0) {
                result[j++] = s[i];
            }
            depth++;
        } else {
            depth--;
            // If depth > 0 after decrementing, this ')' is inside a primitive string
            if (depth > 0) {
                result[j++] = s[i];
            }
        }
    }
    
    // Null-terminate the string
    result[j] = '\0';
    
    return result;
}
