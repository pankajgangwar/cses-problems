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


//Problem : https://cses.fi/problemset/task/1672
//Sol : https://cses.fi/problemset/result/1738524

void floydWarshall(int N, vector<vector<int>> &distTo) {
    // Floyd–Warshall algorithm for all pair shortest path
    // Time : O(n^3)
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (distTo[i][j] > distTo[i][k] + distTo[k][j]) {
                    distTo[i][j] = distTo[i][k] + distTo[k][j];
                }
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
    int cities, connections, queries;
    cin >> cities >> connections >> queries;
    vector<vector<int>> distTo(cities + 1, vector<int> (cities + 1, inf));
    for (int i = 0; i < connections; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        distTo[u][v] = min(distTo[u][v], w);
        distTo[v][u] = min(distTo[v][u], w);
        distTo[u][u] = 0;
        distTo[v][v] = 0;
    }
    floydWarshall(cities, distTo);
    for (int i = 1; i <= queries; i++) {
        int u, v;
        cin >> u >> v;
        if (distTo[u][v] == inf) {
            cout << -1 << '\n';
        } else {
            cout << distTo[u][v] << '\n';
        }
    }
    cout << endl;
}