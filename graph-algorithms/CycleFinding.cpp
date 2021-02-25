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

//Problem : https://cses.fi/problemset/task/1197
//Sol : https://cses.fi/problemset/result/1752977

void bellmanFord(int N) {
    vector<int> dist(N + 1, Inf);
    dist[1] = 0;
    vector<int> parent(N + 1);
    for (int i = 1; i <= N; ++i) {
        parent[i] = -1;
    }
    int x;
    for (int i = 1; i <= N; ++i) {
        x = -1; // Capture last relaxed vertex at nth iteration
        for (int u = 1; u <= N; ++u) {
            for (auto next : graph[u]) {
                int v = next.first;
                int w = next.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = min(dist[v], dist[u] + w);
                    parent[v] = u;
                    x = v;
                }
            }
        }
    } // n iterations

    if (x != -1) {
        cout << "YES\n";
        // Trace back at most n - 1 times to land in cycle
        for (int i = 1; i <= N - 1; i++) {
            x = parent[x];
        }
        vector<int> cycle;
        for (int v = x; ; v = parent[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1) {
                break;
            }
        }
        reverse(cycle.begin(), cycle.end());
        for (auto u : cycle) {
            cout << u << ' ';
        }
        cout << endl;
    } else {
        cout << "NO";
    }

//return dist[N] == NInf ? -1 : dist[N] * (-1);//  Convert sssp(Single source shortes path)
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
        graph[u].push_back({v, w});
    }
    bellmanFord(n);
}