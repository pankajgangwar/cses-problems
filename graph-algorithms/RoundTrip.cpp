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

//Problem : https://cses.fi/problemset/task/1669
//Sol : https://cses.fi/problemset/result/1724910
vector<int> visited;
vector<int> parent;
unordered_map<int, vector<int>> graph;

int startCity = -1;
int endCity = -1;
bool dfs(int curr, int p) {
    visited[curr] = true;
    parent[curr] = p;
    for (auto adj : graph[curr]) {
        if (adj != p) {
            if (visited[adj]) {
                endCity = curr;
                startCity = adj;
                return true;
            } else {
                if (dfs(adj, curr)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool solve(int n) {
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i, -1)) {
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
    int cities, roads;
    cin >> cities >> roads;
    for (int i = 0; i < roads; i++) {
        int a; cin >> a;
        int b; cin >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    visited.resize(cities + 1);
    parent.resize(cities + 1);
    bool status = solve(cities);
    if (!status) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> ans;
        ans.push_back(endCity);
        int curr = endCity;
        while (curr != startCity) {
            curr = parent[curr];
            ans.push_back(curr);
        }
        ans.push_back(endCity);
        cout << ans.size() << endl;
        for (auto a : ans) {
            cout << a << ' ';
        }
        cout << endl;
    }
    return 0;
}