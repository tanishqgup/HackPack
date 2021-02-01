int add(int a, int b) {
    return ((a % mod + b % mod) % mod + mod) % mod;
}
int mul(int a, int b) {
    return ((a % mod * b % mod) % mod + mod) % mod;
}
int sub(int a, int b) {
    return ((a % mod - b % mod) % mod + mod) % mod;
}
int powmod(int a, int b) {
    int res = 1;
    a %= mod;
    for (; b; b >>= 1) {
        if (b & 1)res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
int inverse(int a) {
    return powmod(a, mod - 2);
}
vector<int> fact;
void init(int limit) {
    fact.resize(limit + 1);
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= limit; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
}
int nCk(int n, int k) {
    if (n < k) return 0;
    if (k == 0) return 0;
    return mul(mul(fact[n] , inverse(fact[n - k])) , inverse(fact[k]));
}
