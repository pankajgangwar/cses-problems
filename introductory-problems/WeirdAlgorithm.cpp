#include <array>
#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <vector>
#define int long long int
#define fast_io                                                                \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define pair pair<int, int>
#define mp make_pair
using namespace std;

// Problem : https://cses.fi/problemset/task/1068
// Sol : https://cses.fi/problemset/result/

void helper(int n)
{
    cout << n << " ";
    if (n == 1) return;
    if (n % 2) {
        helper((n * 3) + 1);
    } else {
        helper(n / 2);
    }
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    int n;
    cin >> n;
    helper(n);
    cout << endl;
    return 0;
}