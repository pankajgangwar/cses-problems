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
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int MAX_NODES = 200001;
vector<int> tree[MAX_NODES];
int dist[2][MAX_NODES];
int dfs(int src, int parent, int d, int a) {
    dist[a][src] = d;
    int opt = -1;
    for (int child : tree[src]) {
        if (child != parent) {
            int curr = dfs(child, src, d + 1, a);
            if (opt == -1 || dist[a][curr] > dist[a][opt]) {
                opt = curr;
            }
        }
    }
    return opt == -1 ? src : opt;
}

int main() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t, n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int node_a = dfs(1, 1, 0, 0);
    int node_b = dfs(node_a, node_a, 0, 0);
    cout << node_a << " " << node_b;
    return 0;
}