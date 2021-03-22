#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include <chrono>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;
using namespace std::chrono;


const ll max_ele = 1e6 + 1;
int arr[max_ele] = {0};
//Problem : https://cses.fi/problemset/task/1713
//Sol : https://cses.fi/problemset/result/1822001/


/*
Time : O(n*sqrt(x))
*/
int solve(ll n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i) {
                count += 1;
            } else {
                count += 2;
            }
        }
    }
    return count;
}


void preprocessing() {
    int count = 0;
    memset(arr, 0, sizeof arr);
    for (int i = 1; i < max_ele; i++) {
        int j = 1;
        while (j * i < max_ele) {
            arr[j * i]++;
            j++;
        }
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    preprocessing();
    int t;
    cin >> t;
    while (t-- > 0) {
        ll n;
        cin >> n;
        cout << arr[n] << '\n';
    }
    cout << '\n';
    return 0;
}