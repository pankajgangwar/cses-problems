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

//Problem : https://cses.fi/problemset/task/1158
//Sol : https://cses.fi/problemset/result/1691787/
//https://codeforces.com/blog/entry/70018

int solve(vector<int>& prices, vector<int>& pages, int totalPrice, int n) {
    int dp[n + 1][totalPrice + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= totalPrice; j++) {
            if (j == 0 || i == 0) {
                dp[i][j] = 0;
            } else {
                int opt1 = (i == 1) ? 0 : dp[i - 1][j]; // Only one book, we are not buying this book
                int opt2 = 0;
                if (j - prices[i] >= 0) {
                    opt2 = dp[i - 1][j - prices[i]] + pages[i];
                }
                dp[i][j] = max(opt1, opt2);
            }
        }
    }
    return dp[n][totalPrice];
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    int n, totalPrice;
    cin >> n >> totalPrice;
    vector<int> prices(n + 1, 0), pages(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> prices[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> pages[i];
    }
    int ans = solve(prices, pages, totalPrice, n);
    cout << ans;
    return 0;
}