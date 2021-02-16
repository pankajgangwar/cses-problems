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

int solve(int n, int m, vector<int>& array) {
    int dp[n + 2][m + 2];
    memset(dp, 0, sizeof dp);
    int mod = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        for (int x = 1; x <= m; x++) {
            if(i == 1 ){
                if(array[i] == 0 || array[i] == x){
                    dp[i][x] = 1;
                }else{
                    dp[i][x] = 0;
                }
            }else{
                if(array[i] == 0 || array[i] == x){
                    dp[i][x] = ( ( dp[i - 1][x - 1] + dp[i - 1][x] ) % mod + dp[i - 1][x + 1] ) % mod;
                }else{
                    dp[i][x] = 0;
                }
            }
        }
    }
    int res = 0;
    for(int x = 1; x <= m; x++){
        res = (res + dp[n][x]) % mod;
    }
    return res;
}

int main() {
    fast_io;
    int n, m;
    cin >> n >> m;
    vector<int> array(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> array[i];
    }
    int ans = solve(n, m, array);
    cout << ans;
    return 0;
}