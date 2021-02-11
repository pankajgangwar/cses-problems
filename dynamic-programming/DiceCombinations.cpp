#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#define ll long long
//#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

//Problem : https://cses.fi/problemset/task/1633
int main() {
    fast_io;
    int n, target;
    cin >> n >> target;
    int dp[target + 1];
    int dice[] = {1, 2, 3, 4, 5, 6};
    int mod = (int)1e9 + 7;
    for (int i = 1; i <= target ; i++) {
        for (int j = 0; j < 6; j++) {
            if (i >= dice[j]) {
                dp[i] += dp[i - dice[j]];
                dp[i] = dp[i] % mod;
            }
        }
    }
    int ans = 0;
    cout << dp[target];
    return 0;
}