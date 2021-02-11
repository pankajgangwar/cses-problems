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

//Problem : https://cses.fi/problemset/task/1634

int main() {
    fast_io;
    int n, x;
    cin >> n >> x;
    vector<int> arr;
    arr.resize(n, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    int ans = solve(n);
    cout << ans;
    return 0;
}

int solve(int target) {
    int dice[] = {1, 2, 3, 4, 5, 6};
    int dp[target + 1];
    dp[0] = 1;
    for (int i = 1; i <= target ; i++) {
        for (int j = 0; j < 6; j++) {
            if (dice[j] < i) {
                dp[i] += dp[i - dice[j]];
            }
        }
    }
    return dp[target];
}