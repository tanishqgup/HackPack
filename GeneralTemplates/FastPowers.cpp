int powmod(int a, int b) {
    int res = 1;
    a %= mod;
    for (; b; b >>= 1) {
        if (b & 1)res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

int fast_pow(int a, int b) {
    if (b == 1) return a;
    if (b == 0) return 1;
    int x = fast_pow(a, b / 2);
    x *= x;
    if (b & 1) x *= a;
    return x;
}
