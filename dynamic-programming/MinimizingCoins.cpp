#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include <array>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

//Problem : https://cses.fi/problemset/task/1634
// Sol : https://cses.fi/problemset/result/1689982/

int solve(vector<int> coins, int target) {
    int max = INT_MAX;
    vector<int> dp(target + 1);
    fill(dp.begin(), dp.end(), max);
    dp[0] = 0;
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (i - coins[j] >= 0 ) {
                int sub_res = dp[i - coins[j]];
                if (sub_res != max && sub_res + 1 < dp[i]) {
                    dp[i] = sub_res + 1;
                }
            }
        }
    }
    return dp[target] == max ? -1 : dp[target];
}

int main() {
    fast_io;
    int n, target;
    cin >> n >> target;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int ans = solve(coins, target);
    cout << ans;
    return 0;
}