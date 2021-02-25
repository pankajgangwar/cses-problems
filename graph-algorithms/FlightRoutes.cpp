#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
#define pb push_back
#define pair pair<int,int>
#define mp make_pair
using namespace std;
const int MAX_NODES = 1e5 + 5;
const int Inf = 1e17;
const int NInf = Inf * (-1);
vector<pair> graph[MAX_NODES];
vector<bool> visited(MAX_NODES, false);

//Problem : https://cses.fi/problemset/task/1195
//Sol : https://cses.fi/problemset/result/1754439

void dijkstra(int n, int k) {
    priority_queue<pair, vector<pair>, greater<pair> > minpq;
    vector<vector<int>> dist(n + 1, vector<int>(k + 1, Inf));

    minpq.push( {0, 1} );

    while (!minpq.empty()) {
        auto curr = minpq.top(); minpq.pop();
        int src = curr.second;
        int totalCost = curr.first;
        if (dist[src][k - 1] < totalCost) continue;
        for (auto edge : graph[src]) {
            int dest = edge.first;
            int cost = edge.second;
            if (dist[dest][k - 1] > cost + totalCost) {
                dist[dest][k - 1] = cost + totalCost;
                minpq.push({cost + totalCost, dest});
                sort(dist[dest].begin(), dist[dest].end());
            }
        }
    }
    for (int i = 0; i < k; i++) {
        cout << dist[n][i] << ' ';
    }
    cout << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w });
    }
    dijkstra(n, k);
    cout << endl;
}