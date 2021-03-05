#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

/*
Problem: https://cses.fi/problemset/task/1084/
Solution: https://cses.fi/problemset/result/1783421/
*/
int main() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> desiredSize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> desiredSize[i];
    }

    vector<int> apartmentSize(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> apartmentSize[i];
    }
    sort(desiredSize.begin(), desiredSize.end());
    sort(apartmentSize.begin(), apartmentSize.end());
    int count = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (abs(desiredSize[i] - apartmentSize[j]) <= k) {
            ++i;
            ++j;
            ++count;
        } else {
            if (desiredSize[i] - apartmentSize[j] > k) {
                ++j;
            } else {
                ++i;
            }
        }
    }
    cout << count << '\n';
    return 0;
}

