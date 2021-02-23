#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
#define pb push_back
#define pair pair<int,int>
using namespace std;
const int MAX_NODES = 1e5 + 5;
const int inf = 1e15;
vector<pair> graph[MAX_NODES] ;
vector<int> dist(MAX_NODES , inf );
vector<bool> visited(MAX_NODES, false);

//Problem : https://cses.fi/problemset/task/1671
//Sol : https://cses.fi/problemset/result/1737926
void dijkstra() {
    priority_queue<pair, vector<pair>, greater<pair> > pq; // min priority queue
    dist[1] = 0;
    pq.push( {0, 1} );
    while (!pq.empty()) {
        pair p = pq.top(); pq.pop();
        int src = p.second;
        int src_w = p.first;
        if (visited[src]) continue;
        visited[src] = true;
        for (auto adj : graph[src]) {
            int dest = adj.first;
            int w = adj.second;
            if (visited[dest]) continue;
            if (dist[dest] > src_w + w) {
                dist[dest] = src_w + w;
                pq.push({dist[dest], dest});
            }
        }
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    int cities, connections;
    cin >> cities >> connections;

    for (int i = 0; i < connections; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    dijkstra();
    for (int i = 1; i <= cities; i++) {
        cout << dist[i] << " ";
    }
}