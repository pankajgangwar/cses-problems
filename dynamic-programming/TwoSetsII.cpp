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

//Problem : https://cses.fi/problemset/task/1140
//Sol : https://cses.fi/problemset/result/
//https://codeforces.com/blog/entry/70018

ll solve(int n) {
    int mod = 1e9 + 7;
    int target = ((n * (n + 1)) / 2);
    int maxsum = target / 2;
    ll dp[n + 1][maxsum + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int ele = 1; ele <= n; ele++) {
        for (int cursum = 0; cursum <= maxsum ; cursum++) {
            long opt1 = dp[ele - 1][cursum];
            long opt2 = 0;
            if (cursum - ele >= 0) {
                opt2 = dp[ele - 1][cursum - ele] % mod;
            }
            dp[ele][cursum] += (opt1 + opt2) % mod;
        }
    }
    if (target % 2 != 0) return 0; // If total sum is not even, two sets can't be created
    return dp[n - 1][maxsum];
}

int main() {
    fast_io;
    int n;
    cin >> n;
    ll ans = solve(n);
    cout << ans << endl;
    return 0;
}