#include <bits/stdc++.h>
#define int long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pair pair<int, int>
#define mp make_pair
const int MAX_NODES = 1e5 + 5;
const int mod = 1e9 + 7;
const int Inf = 1e17;
using namespace std;


//Problem : https://cses.fi/problemset/task/1202
//Sol : https://cses.fi/problemset/result/1763499

vector<pair> graph[MAX_NODES];
int min_ways[MAX_NODES];
int dist[MAX_NODES];
int max_f[MAX_NODES];
int min_f[MAX_NODES];

/*
Uses dijkstra's algorithm
*/
void dijkstra(int n) {

    priority_queue<pair, vector<pair>, greater<pair> > min_heap; // min priority queue
    for (int i = 2; i <= n; i++) {
        dist[i] = Inf;
    }
    min_heap.push( {0, 1} );
    dist[1] = 0;
    min_ways[1] = 1;
    while (!min_heap.empty()) {
        pair p = min_heap.top(); min_heap.pop();
        int cost = p.first;
        int u = p.second;
        if (cost > dist[u]) continue;
        for (auto adj : graph[u]) {
            int v = adj.first;
            int w = adj.second;
            if (dist[v] < (cost + w)) continue; // Already optimized from u to v

            if (dist[v] == (cost + w) ) { // New path with same optimal cost
                min_ways[v] = (min_ways[u] + min_ways[v]) % mod;
                min_f[v] = min(min_f[v] , min_f[u] + 1);
                max_f[v] = max(max_f[v] , max_f[u] + 1);
            } else if (dist[v] > (cost + w) ) { //New optimal path from u to v
                min_ways[v] = min_ways[u];
                dist[v] = cost + w;
                min_f[v] = min_f[u] + 1;
                max_f[v] = max_f[u] + 1;

                min_heap.push({dist[v], v}); // Perform relaxation
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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    dijkstra(n);
    cout << dist[n] << ' ' << min_ways[n] << ' ' << min_f[n] << ' ' << max_f[n];
    cout << endl;
}