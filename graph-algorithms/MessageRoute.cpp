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

//Problem : https://cses.fi/problemset/task/1667
//Sol : https://cses.fi/problemset/result/1723148

vector<int> solve(unordered_map<int, vector<int>> graph, int n) {
    bool visited[n + 1] = {false};
    queue<int> bfs;
    unordered_map<int, int> prevTrack;
    bfs.push(1);
    visited[1] = true;
    prevTrack[1] = 0;
    bool isReachable = false;
    while (!bfs.empty()) {
        int computer = bfs.front();
        bfs.pop();
        if (computer == n) {
            isReachable = true;
            break;
        }
        if (graph.find(computer) != graph.end()) {
            for (auto adj : graph[computer]) {
                if (visited[adj]) continue;
                visited[adj] = true;
                prevTrack[adj] = computer;
                bfs.push(adj);
            }
        }
    }

    vector<int> ans;
    if (!isReachable) {
        return ans;
    }
    while (n != 0) {
        ans.push_back(n);
        n = prevTrack[n];
    }
    return ans;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdin);
#endif
    fast_io;
    int computers, connections;
    cin >> computers >> connections;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < connections; i++) {
        int a; cin >> a;
        int b; cin >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> ans = solve(graph, computers);
    if (ans.empty()) {
        cout << "IMPOSSIBLE";
    } else {
        cout << ans.size() << '\n';
        for (int i = ans.size() - 1 ; i >= 0 ; i--) {
            cout << ans[i] << ' ';
        }
    }
    cout << endl;
    return 0;
}