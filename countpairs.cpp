#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 1e6;
vector<int> primes;

// Sieve to generate primes up to 1e6
void sieve() {
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= MAX; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

// Count distinct prime factors
int countDistinctPrimes(ll n) {
    int cnt = 0;
    for (ll p : primes) {
        if (p * p > n) break;
        if (n % p == 0) {
            cnt++;
            while (n % p == 0) n /= p;
        }
    }
    if (n > 1) cnt++; // remaining prime
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(); // precompute primes

    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        int distinct = countDistinctPrimes(n);
        cout << (1LL << distinct) << "\n";
    }
    return 0;
}
