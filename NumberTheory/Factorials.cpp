vector<int> fact;
void init(int limit) {
    fact.resize(limit + 1);
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= limit; i++) {
        fact[i] = (fact[i - 1] * i);
    }
}
int nCk(int n, int k) {
    if (n < k) return 0;
    if (k == 0) return 0;
    return fact[n] / (fact[n - k] * fact[k]);
}
