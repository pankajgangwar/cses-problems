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

//Problem : https://cses.fi/problemset/task/1097
//Sol : https://cses.fi/problemset/result/1703662
//https://codeforces.com/blog/entry/70018

const int max_coins = 5001;
ll memo[max_coins][max_coins];
ll coins[max_coins];

ll solve(int i, int j) {
    if (i > j) {
        return 0;
    }
    if (i + 1 == j) {
        return max(coins[i], coins[j]);
    }
    if (memo[i][j] != -1) return memo[i][j];
    long opt1 = coins[i] + min(solve(i + 2, j), solve(i + 1, j - 1));
    long opt2 = coins[j] + min(solve(i + 1, j - 1), solve(i, j - 2));
    return memo[i][j] = max(opt1, opt2);
}

int main() {
    fast_io;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    memset(memo, -1, sizeof memo);
    ll ans = solve(0, n - 1);
    cout << ans << endl;
    return 0;
}