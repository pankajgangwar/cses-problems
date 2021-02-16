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

//Problem : https://cses.fi/problemset/task/1744
//Sol : https://cses.fi/problemset/result/1691787/
//https://codeforces.com/blog/entry/70018

int solve(int a, int b) {
    int dp[a + 1][b + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j ) {
                dp[i][j] = 0;
            }else {
                dp[i][j] = 1e6;
                for (int k = 1; k <= j - 1 ; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
                for (int k = 1; k <= i - 1 ; k++) {
                    dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
                }
            }
        }
    }
    return dp[a][b];
}

int main() {
    fast_io;
    int a, b;
    cin >> a >> b;
    int ans = solve(a, b);
    cout << ans;
    return 0;
}