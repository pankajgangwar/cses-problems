#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

//Problem : https://cses.fi/problemset/task/2413
//Sol : https://cses.fi/problemset/result/1696649/
//https://codeforces.com/blog/entry/70018

const int max_height = 1e6;
const int mod = 1e9 + 7;
ll dp[max_height + 1][2];

void solve() {
    memset(dp, 0, sizeof dp);
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= max_height; i++) {
        long opt1 = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        long opt2 = (2 * dp[i - 1][0]) % mod;
        long opt3 = dp[i - 1][0];
        long opt4 = dp[i - 1][1];
        dp[i][0] = (opt1 + opt2 + opt3) % mod;
        dp[i][1] = (opt1 + opt4) % mod;
    }
}

int main() {
    fast_io;
    int n, t;
    cin >> t;
    solve();
    while(t-- > 0){
        cin >> n;
        int ans = (dp[n][0] + dp[n][1]) % mod;
        cout << ans << '\n';
    }
    return 0;
}