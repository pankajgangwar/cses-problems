#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <map>
#include <bits/stdc++.h>
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

//Problem : https://cses.fi/problemset/task/1098
//Sol : https://cses.fi/problemset/result/


int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    ll t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        ll x[n];
        ll xr = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            x[i] %= 4;
            xr ^= x[i];
        }
        if (xr != 0) cout << "first";
        else cout << "second";
        cout << "\n";
    }
    return 0;
}