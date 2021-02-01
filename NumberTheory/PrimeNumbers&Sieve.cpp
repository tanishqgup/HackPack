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
    void fill_primes(int limit) {
        if (!isrunsievecalled) {
            cerr << "call runsieve() " << endl;
            exit(1);
        }
        for (int i = 1; i <= limit; i++) {
            if (!prime[i]) {
                primes.pb(i);
            }
        }
        // return primes;
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

    vector<int> factorise(int elem) {
        if (!isfactorsievecalled) {
            cerr << "call factorsieve()" << endl;
            exit(1);
        }
        isfactorsievecalled = 1;
        vector<int> factors;
        while (factorsieve[elem] != 1) {
            factors.pb(factorsieve[elem]);
            elem /= factorsieve[elem];
        }
        sort(all(factors));
        return factors;
    }
    vector<int> factorise1(int elem) {
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
        sort(all(factors));
        return factors;
    }
} ck;
// ck.is_prime() = return a number is prime or not
// ck.run_sieve() = initialize sieve with primes and not primes
// ck.fill_prime() = fill all primes upto given range
// ck.factorisesieve() = initialise factorisation sieve for numbers
// ck.factorise() = return list of prime factorisation of given element
// ck.factorise1() = return list of prime factorisation of single element
