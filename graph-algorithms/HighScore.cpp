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
const int Inf = 1e17;
const int NInf = Inf * (-1);
vector<pair> graph[MAX_NODES];


//Problem : https://cses.fi/problemset/task/1673
//Sol : https://cses.fi/problemset/result/1741714

int bellmanFord(int N) {
    vector<int> dist(N + 1, Inf);
    dist[1] = 0;
    for (int i = 1; i <= N - 1; ++i) {
        for (int u = 1; u <= N; ++u) {
            if (dist[u] == Inf) continue;
            for (auto next : graph[u]) {
                int v = next.first;
                int w = next.second;
                dist[v] = min(dist[v], dist[u] + w);
                dist[v] = max(dist[v], NInf);
            }
        }
    } // n - 1 iterations

    for (int i = 1; i <= N - 1; ++i) {
        for (int u = 1; u <= N; ++u) {
            if (dist[u] == Inf) continue;
            for (auto next : graph[u]) {
                int v = next.first;
                int w = next.second;
                dist[v] = max(dist[v], NInf);
                /*
                Negative cycle leads to relaxation even after n - 1 iterations
                Relaxation: Weight lose
                */
                if (dist[u] + w < dist[v]) { // This confirms presence of negative cycle
                    dist[v] = NInf; // Reset to -infinity
                }
            }
        }
    }
    return dist[N] == NInf ? -1 : dist[N] * (-1);//  Convert sssp(Single source shortes path)
    //to sslp(Single source longest path)
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w * (-1)});
    }
    int ans = bellmanFord(n);
    cout << ans << endl;
}