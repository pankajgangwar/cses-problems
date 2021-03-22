#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <map>
#include <bits/stdc++.h>
#define int long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

//Problem : https://cses.fi/problemset/task/1722
//Sol : https://cses.fi/problemset/result/1830623

const int mod = 1e9 + 7;
int solve1(int n) {
    /* DP solution */
    vector<int> fib(n + 1, 0);
    fib[0] = 0;
    fib[1] = 1;
    if (n == 0 || n == 1) return n;
    for (int i = 2; i <= n; i++) {
        fib[i] = (fib[i - 2] % mod + fib[i - 1] % mod) % mod;
    }
    return fib[n] % mod;
}

int solve2(int n) {
    /* Constant space solution */
    if (n == 0 || n == 1) return n;
    int f1 = 0, f2 = 1, fn = 0;
    for (int i = 2; i <= n + 1; i++) {
        fn = (f1 + f2) % mod;
        f2 = f1 % mod, f1 = fn % mod;
    }
    return fn % mod;
}

map<int, int> fibMap;
int fib(int n) {
    if (fibMap.count(n)) return fibMap[n];
    int k = n / 2;
    if (n % 2 == 0) {
        return fibMap[n] = (fib(k) * fib(k) + fib(k - 1) * fib(k - 1)) % mod;
    } else {
        return fibMap[n] = (fib(k) * fib(k + 1) + fib(k) * fib(k - 1)) % mod;
    }
}


vector<vector<int>> mul(vector<vector<int>> x, vector<vector<int>> y) {
    vector<vector<int>> r(2, vector<int>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                r[i][j] = (r[i][j] + (x[i][k] * y[k][j]) % mod) % mod;
            }
        }
    }
    return r;
}

vector<vector<int>> modpow(vector<vector<int>> a, int n) {
    if (n == 1) {
        return a;
    }
    vector<vector<int>> u = modpow(a, n / 2);
    u = mul(u, u);
    if (n % 2 == 1) u = mul(u, a);
    return u;
}


vector<vector<int>> expo_power(vector<vector<int>> matrix, int n) {
    vector<vector<int>> r(2, vector<int> (2, 0));
    for (int i = 0; i < 2; i++) {
        r[i][i] = 1;
    }
    while (n > 0) {
        if (n % 2 == 1) {
            r = mul(r, matrix);
        }
        matrix = mul(matrix, matrix);
        n = n >> 1;
    }
    return r;
}

int fibWithMultipliers(int n) {
    /* Constant space solution */
    if (n == 0 || n == 1) return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n + 1; i++) {
        int new_a = 0 * a + 1 * b;
        int new_b = 1 * a + 1 * b;
        b = new_b;
        a = new_a;
    }
    return b % mod;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    int n; cin >> n;
    /*fibMap[0] = fibMap[1] = 1;
    cout << (n == 0 ? 0 : fib(n - 1)) << endl;*/
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>> matrix(2, vector<int>(2, 0));
    matrix[0][0] = 0, matrix[0][1] = 1;
    matrix[1][0] = 1, matrix[1][1] = 1;

    vector<vector<int>> ans = expo_power(matrix, n - 1 );
    cout << ans[1][1];
    return 0;
}