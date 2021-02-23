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
//Sol : https://cses.fi/problemset/result/
struct triplet {
    int src, prev, weight;
};
struct compare_triplet {
    bool operator()(triplet const& t1, triplet const& t2) {
        return t1.weight > t2.weight;
    }
};
int dijkstra(int n) {
    priority_queue<triplet, vector<triplet>, compare_triplet > minpq; // min priority queue
    minpq.push( {1, -1, 0} );
    int maxw = NInf;
    int min_cost = 0;
    vector<pair> parent(n + 1);
    parent[1] = {0, 0};
    while (!minpq.empty()) {
        triplet p = minpq.top(); minpq.pop();
        int src = p.src;
        int src_w = p.weight;
        int prev = p.prev;
        if (src == n) {
            min_cost = src_w;
            break;
        }
        if (visited[src]) continue;
        visited[src] = true;
        for (auto adj : graph[src]) {
            int dest = adj.first;
            if (visited[dest]) continue;
            int w = adj.second;
            parent[dest] = mp(src, w);
            minpq.push({dest, src, src_w + w});
        }
    }
    while (n != 0) {
        auto prev = parent[n];
        n = prev.first;
        maxw = max(maxw, prev.second);
    }
    int rem = min_cost - maxw;
    int half = floor(maxw / 2);
    return rem + half;
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
        graph[u].push_back({v, w });
    }
    int ans = dijkstra(n);
    cout << ans << endl;
}