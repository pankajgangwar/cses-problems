#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include <queue>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pair pair<int, int>
#define mp make_pair
using namespace std;

//Problem : https://cses.fi/problemset/task/1678
//Sol : https://cses.fi/problemset/result/1756316
//https://cp-algorithms.com/graph/finding-cycle.html

vector<int> color;
vector<int> parent;
unordered_map<int, vector<int>> graph;

int cycle_start = -1;
int cycle_end = -1;
bool dfs(int u, int p) {
    color[u] = 1;
    parent[u] = p;
    for (auto v : graph[u]) {
        if (color[v] == 0) {
            if (dfs(v, u)) {
                return true;
            }
        } else if (color[v] == 1) {
            cycle_start = v;
            cycle_end = u;
            return true;
        }
    }
    color[u] = 2;
    return false;
}

bool solve(int n) {
    for (int v = 1; v <= n; v++) {
        if (color[v] == 0 && dfs(v, -1)) {
            return true;
        }
    }
    return false;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdin);
#endif
    fast_io;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        int b; cin >> b;
        graph[a].push_back(b);
    }
    color.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    bool status = solve(n);
    if (!status) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << endl;
        for (auto a : cycle) {
            cout << a << ' ';
        }
        cout << endl;
    }
    return 0;
}