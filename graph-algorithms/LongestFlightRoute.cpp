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
const int MAX_NODES = 1e5 + 5;
const int mod = 1e9 + 7;
using namespace std;


//Problem : https://cses.fi/problemset/task/1680
//Sol : https://cses.fi/problemset/result/

vector<int> parent;
vector<int> graph[MAX_NODES];
vector<int> parent[MAX_NODES];
vector<int> indegrees;


/*
Uses Kahn's algorithm
*/
bool topological_sort(int n) {
    queue<int> queue;
    int dp[n + 1];
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (indegrees[i] == 0) {
            queue.push(i);
        }
    }
    pair last = mp(-1, -1);
    parent[1] = -1;
    while (!queue.empty()) {
        int curr = queue.front(); queue.pop();
        if (curr == n) {
            last = curr;
        }
        for (int adj : graph[curr]) {
            indegrees[adj]--;
            if (indegrees[adj] == 0) {
                queue.push(adj);
            }
        }
        for (int prev : parent[curr]) {
            dp[curr] = 1 + dp[prev];
        }
    }
    if (last.first != -1 && last.second != -1) {
        return true;
    } else {
        return false;
    }
    cout << endl;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdin);
#endif
    fast_io;
    int n, m;
    cin >> n >> m;
    indegrees.resize(n + 1);
    parent.assign(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        indegrees[b]++;
        graph[a].push_back(b);
        parent[b].push_back(a);
    }
    bool status = topological_sort(n);
    if (!status) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> ans;
        for (int v = n; v != -1; v = parent[v]) {
            ans.push_back(v);
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto a : ans) {
            cout << a << ' ';
        }
        cout << endl;
    }
    return 0;
}