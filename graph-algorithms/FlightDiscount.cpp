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
struct Item {
    int src, cost;
    bool discount;
    Item(int _src, int _cost, bool _discount){
        src = _src;
        cost = _cost;
        discount = _discount;
    }

    inline const bool operator()(const Item& other) const {
        if()
        return t1.weight > t2.weight;
    }
};
struct compare_Item {
    
};
int dijkstra(int n) {
    priority_queue<Item, vector<Item>, compare_Item > minpq; // min priority queue
    minpq.push( {1, -1, 0} );
    int maxw = NInf;
    int min_cost = 0;
    vector<pair> parent(n + 1);
    parent[1] = {0, 0};
    while (!minpq.empty()) {
        Item p = minpq.top(); minpq.pop();
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