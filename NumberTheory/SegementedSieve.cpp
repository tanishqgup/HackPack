vector<int> primesuptorootr;
void segmentedsieve(int n) {
    int limit = (int)sqrt(n);
    bool marked[limit + 1] = {0};
    for (int i = 2; i * i <= limit; i++) {
        if (!marked[i]) {
            for (int j = i * i; j <= limit; j += i) {
                marked[j] = 1;
            }
        }
    }
    marked[0] = marked[1] = 1;
    marked[2] = 0;
    for (int i = 0; i <= limit; i++) if (!marked[i]) primesuptorootr.pb(i);
}

vector<int> primesltor;
void query(int l, int r) {
    if (l == 1) l++;
    bool marked[r - l + 1] = {0};
    int last = (int)sqrt(r);
    for (int i = 0; i < primesuptorootr.size(); i++) {
        if (primesuptorootr[i] > last) break;
        int firstdivisible = (l / primesuptorootr[i] + (l % primesuptorootr[i] ? 1 : 0)) * primesuptorootr[i];
        if (firstdivisible == primesuptorootr[i]) firstdivisible *= 2;
        for (int j = firstdivisible; j <= r; j += primesuptorootr[i]) {
            marked[j - l] = 1;
        }
    }
    for (int i = l; i <= r; i++) {
        if (!marked[i - l]) {
            primesltor.pb(i);
        }
    }
}

// call segmentedsieve(int lastrange) lastrange what is the maximum value possible of A_i
// if you have to find primes between l and r where abs(l-r)<=1e6 call query function
// **Don't forget to clear primesltor vector after every query
