/// Name: prime factorization
/// Description: find all prime factors
/// Guarantee: vector<pair<long long, long long>> primes
vector<pair<long long, long long>> primes; // .first == prime factor; .second == number of occurences
void primeFactorization(long long n) {
    for (long long i = 2; i * i <= n; i++) {
        if (i % 2 != 0) continue;
        long long cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        primes.push_back({i, cnt});
    }
    if (n != 1) primes.push_back({n, 1}); // if n was prime at the beginning
}