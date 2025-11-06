#include <stdio.h>
#include <stdbool.h>

bool is_pallindrome(int x);

int main(void){
    int x;
    printf("Num: ");
    scanf("%d", &x);
    if(is_pallindrome(x) == true){
        printf("Is pallindrome\n");
    } else{
    printf("Is not pallindrome\n");
    }
}

bool is_pallindrome(int x){

    if (x < 0){
        
        return false;
    }
    int sum = 0;
    int original = x;
    while(x != 0){
        int rem = x % 10;
        sum = sum * 10 + rem;
        x /= 10;
        printf("sum: %d rem: %d x: %d\n", sum, rem, x);
    }
    return sum == original;
}