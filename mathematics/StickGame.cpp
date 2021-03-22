#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <map>
#include <bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

//Problem : https://cses.fi/problemset/task/1729
//Sol : https://cses.fi/problemset/result/1863641

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    int n, k;
    cin >> n >> k;
    int arr[k];
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    bool dp[n + 1] = {};
    dp[0] = false;
    for (int i = 1; i <= n; i++) {
        dp[i] = false;
        for (int j = 0; j < k; j++) {
            int sticks = arr[j];
            if (i - sticks >= 0 && !dp[i - sticks]) {
                dp[i] = true;
            }
        }
        cout << (dp[i] ? "W" : "L");
    }
    cout << endl;
    return 0;
}