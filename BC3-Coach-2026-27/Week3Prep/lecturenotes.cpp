int F(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return F(n - 1) + F(n - 2);
}