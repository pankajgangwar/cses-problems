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
// Problem : https://cses.fi/problemset/task/1633
// https://cses.fi/problemset/result/1689995/

int main() {
    fast_io;
    int target;
    cin >> target;
    vector<int> dp(target + 1, 0);
    int dice[] = {1, 2, 3, 4, 5, 6};
    int mod = 1e9 + 7;
    dp[0] = 1;
    for (int i = 1; i <= target ; i++) {
        for (int j = 0; j < 6; j++) {
            if (i >= dice[j]) {
                dp[i] += dp[i - dice[j]];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[target];
    return 0;
}