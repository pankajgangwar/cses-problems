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

//Problem : https://cses.fi/problemset/task/1745
//Sol : https://cses.fi/problemset/result/1703012
//https://codeforces.com/blog/entry/70018
// 0-1 knapsack

vector<int> solve(vector<int> coins, int n) {
    ll maxsum = accumulate(coins.begin(), coins.end(), 0);
    bool dp[n + 1][maxsum + 1];
    memset(dp, false, sizeof dp);
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= maxsum; j++) {
            bool opt1 = dp[i - 1][j]; // If its possible to make amount j using i -1 coins without ith coin
            bool opt2 = false;// Or if its possible to make amount j using i - 1 coins with using ith coin
            if (j - coins[i] >= 0) {
                opt2 = dp[i - 1][j - coins[i]];
            }
            dp[i][j] = opt1 || opt2;
        }
    }
    vector<int> res;
    for (int j = 1; j <= maxsum; j++) {
        if (dp[n][j]) {
            res.push_back(j);
        }
    }
    return res;
}

int main() {
    fast_io;
    int n;
    cin >> n;
    vector<int> coins(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }
    vector<int> ans = solve(coins, n);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
    return 0;
}