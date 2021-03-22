#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include <chrono>
#include <cmath>
#include <iomanip>
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
const ll mod = 1e9 + 7;

//Problem : https://cses.fi/problemset/task/1713
//Sol : https://cses.fi/problemset/result/1822001/

ll ap_summation(ll l, ll r) {
    ll xx = r - l + 1;
    ll yy = l + r;
    if (xx % 2 == 0) xx /= 2;
    else yy /= 2;
    xx %= mod, yy %= mod;
    return (xx % mod * yy % mod);
}

ll solution(ll n) {
    ll i = 1, minVal = n;
    ll ans = 0;
    while (i * i <= n) {
        ll l = n / (i + 1);
        ll r = (n / i);
        if (l >= r) continue;
        ans = (ans + (i * ap_summation(l + 1, r) % mod) % mod) % mod;
        minVal = l;
        i += 1;
    }
    for (ll j = 1; j < minVal + 1; j++) {
        ans = (ans + (j * (n / j) % mod) % mod) % mod;
    }
    return ans % mod;
}


ll solve1(ll n) {
    ll ans = 0;
    for (ll i = 1, la; i <= n; i = la + 1) {
        ll q = n / i;
        la = n / (n / i);
        ll ap_sum = ap_summation(i, la);
        ans = (ans + q % mod * ap_sum % mod) % mod;
    }
    return ans % mod;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    ll n;
    cin >> n;
    cout << solve1(n);
    return 0;
}