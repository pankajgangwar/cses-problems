#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pair pair<int, int>
#define mp make_pair
using namespace std;

// Path Queries
//https://cses.fi/problemset/task/1750/
//https://cses.fi/problemset/result/1764550

const ll MAX_NODES = 2e5 + 5;
const int MAX_DEPTH = 30;
int up[MAX_NODES][MAX_DEPTH];
vector<int> graph[MAX_NODES];

/*
Time : O(NlogN)
 */
void binary_lifting(ll n) {
    /*
        2^i = 2^(i-1) + 2^(i-1)
        Binary lifting on directed graph
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


/*
Time: O(logN)
 */
int findLCA(int u, int v) {
    if (lvl[u] < lvl[v]) {
        swap(u, v);
    }
    u = lift_node(u, lvl[u] - lvl[v]);
    if (u == v) return u;
    for (int i = MAX_DEPTH - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return lift_node(u, 1);
}

/*
Time: O(logN)
 */
int distance_between(int u, int v) {
    int lca = findLCA(u, v);
    if (lvl[u] < lvl[v]) {
        swap(u, v);
    }
    int distance = (lvl[u] - lvl[v]);
    if (lca != u && lca != v) {
        int d = (lvl[v] - lvl[lca]) * 2;
        distance += d;
    }
    return distance;
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