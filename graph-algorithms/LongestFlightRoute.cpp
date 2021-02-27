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
//Sol : https://cses.fi/problemset/result/1761183

vector<int> graph[MAX_NODES];
vector<int> parent[MAX_NODES];
vector<int> indegrees;
vector<int> dist;
vector<int> track_path;
int min_value = INT_MIN;

/*
Uses Kahn's algorithm
*/
void topological_sort(int n) {
    queue<int> queue;
    dist[1] = 1;
    for (int i = 1; i <= n; i++) {
        if (indegrees[i] == 0) {
            queue.push(i);
        }
    }
    while (!queue.empty()) {
        int curr = queue.front(); queue.pop();
        for (int adj : graph[curr]) {
            indegrees[adj]--;
            if (indegrees[adj] == 0) {
                queue.push(adj);
            }
        }
        int max_curr = min_value;
        int max_node = -1;
        for (int prev : parent[curr]) {
            if (max_curr < dist[prev] + 1) {
                max_curr = dist[prev] + 1;
                max_node = prev;
            }
        }
        if (curr == 1) continue;
        dist[curr] = max_curr;
        track_path[curr] = max_node;// max length to reach this node
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    int n, m;
    cin >> n >> m;
    indegrees.resize(n + 1, 0);
    dist.resize(n + 1, min_value);
    track_path.resize(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        indegrees[b]++;
        graph[a].push_back(b);
        parent[b].push_back(a);
    }
    topological_sort(n);
    if (dist[n] < 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> ans;
        for (int v = n; v != -1 && dist[v] >= 0; v = track_path[v]) {
            ans.push_back(v);
        }
        reverse(ans.begin(), ans.end());
        cout << dist[n] << '\n';
        for (auto a : ans) {
            cout << a << ' ';
        }
        cout << endl;
    }
    return 0;
}