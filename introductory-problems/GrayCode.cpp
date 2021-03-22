#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <map>
#include <bits/stdc++.h>
#define int long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pair pair<int, int>
#define mp make_pair
using namespace std;

//Problem : https://cses.fi/problemset/task/2205
//Sol : https://cses.fi/problemset/result/

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    int n;
    cin >> n;
    for (int i = 0; i < 1 << n; i++) {
        int code = i ^ (i >> 1);
        cout << bitset<n>(code) << '\n';
        //cout << ( i ^ (i >> 1)) << '\n';
    }
    cout << endl;
    return 0;
}