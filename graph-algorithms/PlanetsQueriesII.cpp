#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pair pair<int, int>
#define mp make_pair
using namespace std;

//https://cses.fi/problemset/task/1160/
//https://cses.fi/problemset/result/1765462/
/*
Functional graph/Successor graph
Directed graphs in which every vertex has exactly one outgoing edge.
*/

const ll MAX_NODES = 2e5 + 5;
const int MAX_DEPTH = 30;
int up[MAX_NODES][MAX_DEPTH];
vector<int> graph[MAX_NODES];
int lvl[MAX_NODES] = {0};
bool visited[MAX_NODES];
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

void dfs(int src) {
    if (visited[src]) return;
    visited[src] = true;
    int parent = up[src][0];
    dfs(parent);
    lvl[src] = lvl[parent] + 1;
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

int distance_between(int u, int v) {
    int start_of_cycle = lift_node(u, lvl[u]);
    if (lift_node(u, lvl[u] - lvl[v]) == v) {
        // If v is in front of u within a cycle
        return (lvl[u] - lvl[v]);
    } else if (lift_node(start_of_cycle , lvl[start_of_cycle] - lvl[v]) == v) {
        // If u is in front of v within a cycle
        return (lvl[start_of_cycle] + (lvl[u] - lvl[v]) );
    } else {
        return -1;
    }
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
        int v;
        cin >> v;
        graph[u].push_back(v);
        up[u][0] = v;
    }
    binary_lifting(n);
    for (int u = 1; u <= n; u++) {
        if (!visited[u]) {
            dfs(u);
        }
    }

    while (q-- > 0) {
        int u, v;
        cin >> u >> v;
        int ans = distance_between(u, v);
        cout << ans << '\n';
    }
    return 0;
}