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

//Problem : https://cses.fi/problemset/task/1140
//Sol : https://cses.fi/problemset/result/1709195
//https://codeforces.com/blog/entry/70018
struct project {
    int start, end, reward;
};
bool comp(project p1, project p2) {
    return (p1.end < p2.end);
}
int findBestProject(project array[], int idx) {
    int low = 0, high = idx - 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (array[mid].end < array[idx].start) {
            if (array[mid + 1].end < array[idx].start) {
                low = mid + 1;
            } else {
                return mid; // One based index
            }
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    fast_io;
    int n;
    cin >> n;
    struct project array[n];
    for (int i = 0; i < n; i++ ) {
        cin >> array[i].start >> array[i].end >> array[i].reward;
    }
    sort(array, array + n, comp);
    ll dp[n];
    memset(dp, 0, sizeof dp);
    dp[0] = array[0].reward;
    for (int i = 1; i < n; i++) {
        long opt1 = dp[i - 1];
        long opt2 = array[i].reward;
        int search = findBestProject(array, i);
        if (search != -1) opt2 += dp[search];
        dp[i] = max(opt1, opt2);
    }
    cout << dp[n - 1] << endl;
    return 0;
}