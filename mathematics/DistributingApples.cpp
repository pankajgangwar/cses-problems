#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include <chrono>
#define int long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

//Problem : https://cses.fi/problemset/task/1716
//Sol : https://cses.fi/problemset/result/1837333

const int N = 2 * 1e6;
const int mod = 1e9 + 7;

int inverseOfNumber[N + 1];
void calculateInverse() {
    inverseOfNumber[0] = inverseOfNumber[1] = 1;
    for (int i = 2; i <= N; i++) {
        inverseOfNumber[i] = inverseOfNumber[mod % i] * (mod - mod / i) % mod;
    }
}
int inverseOfFact[N + 1];
void calculateFactorialInv() {
    inverseOfFact[0] = inverseOfFact[1] = 1;
    for (int i = 2; i <= N; i++) {
        inverseOfFact[i] = (inverseOfNumber[i] % mod * inverseOfFact[i - 1] % mod) % mod;
    }
}
int fact[N + 1];
void factorial() {
    fact[0] = 1;
    // n! = n * (n - 1)!
    for (int i = 1; i <= N; i++) {
        fact[i] = (i * fact[i - 1]) % mod;
    }
}

/*
Ways to distribute m mangoes to n people :
1) m identical and n identical:
    (m+n-1)!/((n-1)!*(m)!) -> (m + n - 1) C (n-1)
2) m unique and n identical:
    (m+n-1)!/((n-1)! -> (m + n - 1) C (n-1) * m!
3) m identical and n unique:
    (m+n-1)!/m! -> (m + n - 1) C (n-1) * (n-1)!
4) Both unique
    (m+n-1)! -> (m + n - 1) C (n-1) * (n-1)! * m!
*/

int32_t main() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    calculateInverse();
    calculateFactorialInv();
    factorial();

    int n, m;
    cin >> n >> m;

    int ans = fact[(m + n - 1) % mod] % mod * (inverseOfFact[m] % mod * inverseOfFact[n - 1] % mod) % mod;
    ans %= mod;
    cout << ans % mod << endl;
    return 0;
}