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

//Problem : https://cses.fi/problemset/task/1715
//Sol : https://cses.fi/problemset/result/1835936

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


int32_t main() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    calculateInverse();
    calculateFactorialInv();
    factorial();

    string s; cin >> s;
    int len = s.size();

    int freq[26];
    memset(freq, 0, sizeof freq);

    for (int i = 0; i < len; i++) {
        int idx = s.at(i) - 'a';
        freq[idx]++;
    }

    vector<int> repeated;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 1) {
            repeated.push_back(freq[i]);
        }
    }

    int ans = fact[len] % mod;
    for (auto xx : repeated) {
        ans = (ans * inverseOfFact[xx]) % mod;
    }

    cout << ans << endl;
    return 0;
}