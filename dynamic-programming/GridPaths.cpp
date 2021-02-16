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

//Problem : https://cses.fi/problemset/task/1638
//Sol : https://cses.fi/problemset/result/1688493

int solve(vector<vector<int>>& grid, int n) {
    int dp[n + 1][n + 1];
    /*for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }*/
    //memset(dp, 0, sizeof dp);
    dp[0][1] =  1;
    int mod = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i - 1][j - 1] == 1) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= mod;
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return dp[n][n];
}

int main() {
    fast_io;
    int n;
    cin >> n;
    vector<vector<int>> grid;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        vector<int> curr_row;
        for (int j = 0; j < n; j++){
            curr_row.push_back(row.at(j) == '.' ? 1 : -1);
        }
        grid.push_back(curr_row);
    }
    int ans = solve(grid, n);
    cout << ans;
    return 0;
}