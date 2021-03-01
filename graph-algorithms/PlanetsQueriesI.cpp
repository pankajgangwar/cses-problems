#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pair pair<int, int>
#define mp make_pair
using namespace std;

// Path Queries
//https://cses.fi/problemset/task/1750/
//https://cses.fi/problemset/result/

const ll MAX_NODES = 2e5 + 5;
const int MAX_DEPTH = 30;
int up[MAX_NODES][MAX_DEPTH];

/*
Time : O(NlogN)
 */
void binary_lifting(ll n) {
    /*
        2^i = 2^(i-1) + 2^(i-1)
     */
    for (int i = 1; i < MAX_DEPTH; i++) {
        for (int src = 1; src <= n; src++) {
            if (up[src][i - 1] != -1) { // node at 2^(i-1) level up
                int ancestor = up[src][i - 1];
                up[src][i] = up[ancestor][i - 1];
            } else {
                up[src][i] = -1;
            }
        }
    }
}

/*
 Time : O(logN)
*/
int lift_node(int node, int jump_required) {
    if (jump_required == 0) {
        return node;
    }
    for (int i = MAX_DEPTH - 1; i >= 0 && node != -1; --i) {
        if ((jump_required & (1 << i)) != 0) { // Check if ith bit is set
            node = up[node][i];
        }
    }
    return node;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io
    ll t, n, q, u, v;
    cin >> n >> q;
    for (int u = 1; u <= n; u++) {
        cin >> up[u][0];
    }
    binary_lifting(n);
    while (q-- > 0) {
        int u, jump_required;
        cin >> u >> jump_required;
        int ans = lift_node(u, jump_required);
        cout << ans << '\n';
    }
    return 0;
}