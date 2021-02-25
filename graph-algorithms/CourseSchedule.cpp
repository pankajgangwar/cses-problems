#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define pair pair<int,int>
#define mp make_pair
using namespace std;
const int MAX_NODES = 1e5 + 5;
vector<int> indegrees;
vector<int> prerequisites[MAX_NODES];

//Problem : https://cses.fi/problemset/task/1679
//Sol : https://cses.fi/problemset/result/1755268

void topological_sort(int n) {
    vector<int> order(n + 1, 0);
    int index = 1;
    queue<int> queue;
    for (int i = 1; i <= n; i++) {
        if (indegrees[i] == 0) {
            order[index++] = i;
            queue.push(i);
        }
    }
    while (!queue.empty()) {
        int course = queue.front(); queue.pop();
        for (int adj : prerequisites[course]) {
            indegrees[adj]--;
            if (indegrees[adj] == 0) {
                order[index++] = adj;
                queue.push(adj);
            }
        }
    }
    if (n == index - 1) {
        for (int i = 1; i < order.size(); i++ ) {
            cout << order[i] << ' ';
        }
    } else {
        cout << "IMPOSSIBLE";
    }
    cout << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    int n, m;
    cin >> n >> m;
    indegrees.resize(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        indegrees[b]++;
        prerequisites[a].push_back(b);
    }
    topological_sort(n);
    cout << endl;
}