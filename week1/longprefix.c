#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize);

int main(void){
    char *arr[] = {"flower", "flow", "flight"};
    char **s = arr;
    for(int i = 0; i<3; i++){
        for(int j = 0; j < strlen(s[i]); j++){
            printf("-%c-",s[i][j]);
        }printf("\n");
        printf("%s\n", s[i]);
    }
    char *res = longestCommonPrefix(s, 3);
    printf("Result: %s\n", res);
    return 0;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    // Find length of shortest string
    int minLen = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if (len < minLen)
            minLen = len;
    }

    // Allocate buffer for prefix
    char *prefix = malloc(minLen + 1);
    if (!prefix) exit(1);

    int idx = 0;

    // Compare characters horizontally
    for (int j = 0; j < minLen; j++) {
        char c = strs[0][j];

        for (int i = 1; i < strsSize; i++) {
            if (strs[i][j] != c) {
                prefix[idx] = '\0';
                return prefix;
            }
        }
        prefix[idx++] = c;
    }

    prefix[idx] = '\0';
    return prefix;
}
