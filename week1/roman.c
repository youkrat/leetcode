#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int romanToInt(char* s){
   int res = 0;
   int pre = 0;
   char roman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
   int val[7] = {1,5,10,50,100,500,1000};
   for(int i =strlen(s)- 1; i>=0; i--){
    for(int j = 0; j < 7; j++){
        if(s[i] == roman[j]){
            if(val[j]< pre){
                res-=pre;
                pre-=val[j];
                res+=pre;
            }else{
                res+=val[j];
                pre = val[j];
            }
        }
    }
   }
   return res;
}

char *get_string(char *prompt) {
    char temp[100];
    printf("%s", prompt);
    
   
    if (scanf("%99s", temp) != 1) {
        return NULL;
    }

    char *result = malloc(strlen(temp) + 1);
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(result, temp);
    return result;
}
int main(void){
    char* roman = get_string("Enter number in Roman Numerals: ");
    for(int i = 0; i < strlen(roman); i++){
        roman[i] = toupper(roman[i]);
    }
    printf("Result is: %d\n", romanToInt(roman));
}