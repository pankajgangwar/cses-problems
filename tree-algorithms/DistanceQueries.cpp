#include <stdio.h>
#include <string.h>
#include <iostream>
#include <unordered_map>
#include <array>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#include <queue>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

// Distance Queries
//https://cses.fi/problemset/task/1135/
//https://cses.fi/problemset/result/1519670/

const int MAX_NODES = 200001;
const int MAX_DEPTH = 20;
vector<int> tree[MAX_NODES];
int up[MAX_NODES][MAX_DEPTH];
int lvl[MAX_NODES] = {0};

/*
Time : O(NlogN)
 */
void binary_lifting(int src, int parent) {
    /*
        2^i = 2^(i-1) + 2^(i-1)
     */
    up[src][0] = parent;// node at 2^0 level up
    for (int i = 1; i < MAX_DEPTH; i++) {
        if (up[src][i - 1] != -1) { // node at 2^(i-1) level up
            int ancestor = up[src][i - 1];
            up[src][i] = up[ancestor][i - 1];
        } else {
            up[src][i] = -1;
        }
    }
    for (int child : tree[src]) {
        if (child != parent) {
            lvl[child] = lvl[src] + 1;
            binary_lifting(child, src);
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
    fast_io;
    ll t, n, q, u, v;
    //cin >> t;
    /*
    while(t-- > 0){

    }
     */
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    binary_lifting(1, -1);
    while (q-- > 0) {
        int u, v;
        cin >> u >> v;
        int ans = distance_between(u, v);
        cout << ans << '\n';
    }
    return 0;
}