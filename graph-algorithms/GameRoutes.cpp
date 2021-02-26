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


//Problem : https://cses.fi/problemset/task/1681
//Sol : https://cses.fi/problemset/result/1761418

vector<int> graph[MAX_NODES];
vector<int> parent[MAX_NODES];
vector<int> indegrees;
vector<int> dp;
int min_value = INT_MIN;

/*
Uses Kahn's algorithm
*/
void topological_sort(int n) {
    queue<int> queue;
    dp[1] = 1;
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
        for (int prev : parent[curr]) {
            dp[curr] = (dp[prev] + dp[curr]) % mod;
        }
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdin);
#endif
    fast_io;
    int n, m;
    cin >> n >> m;
    indegrees.resize(n + 1, 0);
    dp.resize(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        indegrees[b]++;
        graph[a].push_back(b);
        parent[b].push_back(a);
    }
    topological_sort(n);
    cout << dp[n] << endl;
    return 0;
}