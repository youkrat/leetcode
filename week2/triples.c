#include <stdio.h>
#include <math.h>

int countTriples(int n);

int main(void){
    int n = 10;
    int ans = countTriples(n);
    printf("%d\n", ans);
}
// Euclid's formula cannot solve this leetcode problem directly

/*int countTriples(int n) {
    int count = 0;

    for (int m = 2; m * m <= n * 2; m++) {
        for (int p = 1; p < m; p++) {

            int a = m*m - p*p;
            int b = 2*m*p;
            int c = m*m + p*p;

            if (c <= n) {
                printf("a=%d b=%d c=%d\n", a, b, c);
                count++;
            }
        }
    }

    return count*2;
}
*/

// brute force solution
int countTriples(int n) {
    int count = 0;

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {

            int c2 = a*a + b*b;
            int c = (int)sqrt(c2);

            if (c*c == c2 && c <= n) {
                count++;
            }
        }
    }

    return count;
}