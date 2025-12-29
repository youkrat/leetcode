#include <stdio.h>
#include<time.h>

int countOdds(int low, int high);

int main(void){
    int low = 3;
    int high = 7;
    int result = countOdds(low, high);
    printf("Count of odd numbers between %d and %d is: %d\n", low, high, result);
    return 0;
}

int countOdds(int low, int high){
    return (high + 1)/2 - (low/2);
}
