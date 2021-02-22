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
using namespace std;

//Problem : https://cses.fi/problemset/task/1668
//Similar : https://leetcode.com/problems/is-graph-bipartite
//Sol : https://cses.fi/problemset/result/1723293

vector<int> solve(unordered_map<int, vector<int>> graph, int n) {
    vector<int> teams(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (teams[i] != 0) continue;
        teams[i] = 1;
        queue<int> bfs;
        bfs.push(i);
        while (!bfs.empty()) {
            int pupil = bfs.front();
            bfs.pop();
            if (graph.find(pupil) != graph.end()) {
                for (auto adj : graph[pupil]) {
                    if (teams[adj] != 0) {
                        if (teams[adj] == teams[pupil]) {
                            teams.resize(0);
                            return teams;
                        }
                    } else {
                        teams[adj] = teams[pupil] == 1 ? 2 : 1;
                        bfs.push(adj);
                    }
                }
            }
        }
    }
    return teams;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdin);
#endif
    fast_io;
    int pupils, friendships;
    cin >> pupils >> friendships;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < friendships; i++) {
        int a; cin >> a;
        int b; cin >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> ans = solve(graph, pupils);
    if (ans.empty()) {
        cout << "IMPOSSIBLE";
    } else {
        for (int i = 1 ; i < ans.size() ; i++) {
            cout << ans[i] << ' ';
        }
    }
    cout << endl;
    return 0;
}