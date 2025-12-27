int sqrt_helper(int number, double guess) {
    double next = (guess + number / guess) / 2.0;

    if ((int)next == (int)guess)
        return (int)guess;

    return sqrt_helper(number, next);
}

int mySqrt(int x) {
    if (x < 0) return -1;
    if (x == 0 || x == 1) return x;

    return sqrt_helper(x, x / 2.0);
}
