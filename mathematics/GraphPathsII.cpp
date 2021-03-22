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

//Problem : https://cses.fi/problemset/task/1724
//Sol : https://cses.fi/problemset/result/1842708

const int mod = 1e9 + 7;
const int inf = 4e18;

vector<vector<int>> mul(vector<vector<int>> x, vector<vector<int>> y, int n) {
    vector<vector<int>> r(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                r[i][j] = min(r[i][j], (x[i][k] + y[k][j]) );
            }
        }
    }
    return r;
}

vector<vector<int>> modpow(vector<vector<int>> a, int n, int k) {
    if (k == 1) {
        return a;
    }
    vector<vector<int>> u = modpow(a, n, k / 2);
    u = mul(u, u, n);
    if (k % 2 == 1) u = mul(u, a, n);
    return u;
}


vector<vector<int>> expo_power(vector<vector<int>> matrix, int n, int k) {
    vector<vector<int>> r(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        r[i][i] = 1;
    }
    while (k > 0) {
        if (k % 2 == 1) {
            r = mul(r, matrix, n);
        }
        matrix = mul(matrix, matrix, n);
        k = k >> 1;
    }
    return r;
}

int32_t main() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    clock_t tStart = clock();
#endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> matrix(n, vector <int> (n, inf));
    while (m-- > 0) {
        int u, v , w;
        cin >> u >> v >> w;
        u--, v--;
        matrix[u][v] = min(matrix[u][v], w);
    }
    vector<vector<int>> ans = modpow(matrix, n, k);
    int res = ans[0][n - 1];
    if (res == inf) {
        cout << -1;
    } else {
        cout << res;
    }
    cout << endl;

#ifndef ONLINE_JUDGE
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}