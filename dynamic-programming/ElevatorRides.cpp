#include<bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <unordered_map>
#include <array>
#include <vector>
#include <set>
#include <queue>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
using namespace std;

void init_code() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
Problem : https://cses.fi/problemset/task/1653/
Sol : https://cses.fi/problemset/result/2824465/
*/
int minSessions(vector<int>& tasks, int sessionTime) {
    const int N = tasks.size();
    const int INF = 1e9;
    vector<pair <int, int> > dp(1 << N, {INF, INF});
    dp[0] = {0, INF};
    for (int mask = 1; mask < (1 << N); ++mask) {
        pair<int, int> best = {INF, INF};
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                pair<int, int> cur = dp[mask ^ (1 << i)];
                if (cur.second + tasks[i] > sessionTime) {
                    cur = {cur.first + 1, tasks[i]};
                } else {
                    cur.second += tasks[i];
                }
                best = min(best, cur);
            }
        }
        dp[mask] = best;
    }
    return dp[(1 << N) - 1].first;
}


int main() {
    //init_code();
    int t = 1;
    //cin >> t;
    while (t--) {
        read(n);
        read(x);
        vector<int> weights(n);
        for (int i = 0; i < n; i++) {
            cin >> weights[i];
        }
        int res = minSessions(weights, x);
        cout << res;
    }
    return 0;
}