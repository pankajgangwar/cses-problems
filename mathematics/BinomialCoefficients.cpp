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

//Problem : https://cses.fi/problemset/task/1079
//Sol : https://cses.fi/problemset/result/1835229/

const int N = 1e6;
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
        inverseOfFact[i] = (inverseOfNumber[i] * inverseOfFact[i - 1]) % mod;
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

int binomialCoefficients(int n, int k) {
    int ans = ((fact[n] * inverseOfFact[k]) % mod * inverseOfFact[n - k]) % mod;
    return ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    calculateInverse();
    calculateFactorialInv();
    factorial();
    int q; cin >> q;
    while (q-- > 0) {
        int n; cin >> n;
        int k; cin >> k;
        int ans = binomialCoefficients(n, k);
        cout << ans << '\n';
    }
    return 0;
}