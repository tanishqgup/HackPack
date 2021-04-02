struct primetheory {
    bool is_prime(int elem) {
        if (elem <= 1) return false;
        if (elem <= 3) return true;
        if (elem % 2 == 0 || elem % 3 == 0) return false;
        for (int i = 5; i * i <= elem; i += 6) {
            if (elem % i == 0 || elem % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    bool *prime;
    bool isrunsievecalled = 0, isfactorsievecalled = 0;
    void run_sieve(int limit) {
        isrunsievecalled = 1;
        prime = new bool[limit + 1] {};
        for (int i = 2; i <= limit; i += 2) prime[i] = 1;
        for (int i = 2; i * i <= limit; i++) {
            if (!prime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    prime[j] = 1;
                }
            }
        }
        prime[0] = prime[1] = 1;
        prime[2] = 0;
    }
    vector<int> primes;
    vector<int> fill_primes(int limit) {
        if (!isrunsievecalled) {
            cerr << "call runsieve() " << endl;
            exit(1);
        }
        for (int i = 1; i <= limit; i++) {
            if (!prime[i]) {
                primes.pb(i);
            }
        }
        return primes;
    }

    vector<int> factorsieve;
    void factorisesieve(int limit) {
        isfactorsievecalled = 1;
        factorsieve.resize(limit + 1, -1);
        factorsieve[0] = factorsieve[1] = 1;
        for (int i = 2; i * i <= limit; i++) {
            if (factorsieve[i] == -1) {
                factorsieve[i] = i;
                for (int j = i * i; j <= limit; j += i) {
                    factorsieve[j] = i;
                }
            }
        }
        for (int i = 0; i <= limit; i++) {
            if (factorsieve[i] == -1) {
                factorsieve[i] = i;
            }
        }
    }

    vector<pair<int, int>> convert_to_pairs(vector<int> &factors) {
        sort(all(factors));
        vector<pair<int, int>> to_return;
        int prev = factors[0], cnt = 1;
        for (int i = 1; i < sz(factors); i++) {
            if (factors[i] == prev) {
                cnt++;
                continue;
            }
            to_return.pb({prev, cnt});
            prev = factors[i], cnt = 1;
        }
        to_return.pb({prev, cnt});
        return to_return;
    }

    vector<pair<int, int>> factorise(int elem) {
        if (!isfactorsievecalled) {
            cerr << "call factorsieve()" << endl;
            exit(1);
        }
        if (elem == 1) return {{1, 1}};
        isfactorsievecalled = 1;
        vector<int> factors;
        while (factorsieve[elem] != 1) {
            factors.pb(factorsieve[elem]);
            elem /= factorsieve[elem];
        }
        return convert_to_pairs(factors);
    }
    vector<pair<int, int>> factorise1(int elem) {
        if (elem == 1) return {{1, 1}};
        vector<int> factors;
        for (int i = 2; i * i <= elem; i++) {
            if (elem % i == 0) {
                while (elem % i == 0) {
                    elem /= i;
                    factors.pb(i);
                }
            }
        }
        if (elem > 1) factors.pb(elem);
        return convert_to_pairs(factors);
    }
    vector<int> canocalise(int elem, bool single_element = false) {
        vector<pair<int, int>> factors;
        factors = (single_element ? factorise1(elem) : factorise(elem));
        vector<int> ans;
        for (int i = 0; i < sz(factors); i++) {
            if (factors[i].ss & 1)
                ans.pb(factors[i].ff);
        }
        return ans;
    }
} ck;
