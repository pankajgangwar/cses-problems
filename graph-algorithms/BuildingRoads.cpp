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

//Problem : https://cses.fi/problemset/task/1666
//Sol : https://cses.fi/problemset/result/1721332
struct UnionFind {
    int count;
    vector<int> parent, rank;
    UnionFind(int n) {
        this->count = n;
        parent.assign(n, 0);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int p) {
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];    // path compression by halving
            p = parent[p];
        }
        return p;
    }
    void combine(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;
        if (rank[rootQ] > rank[rootP]) {
            parent[rootP] = rootQ; // p points to q
        } else {
            parent[rootQ] = rootP; // q points to p
            if (rank[rootP] == rank[rootQ]) {
                rank[rootP]++;
            }
        }
        count--;
    }
    /*int count() {
        return count;
    }*/
};

vector<pair> solve(unordered_map<int, vector<int>> graph, int n) {
    vector<pair> ans;
    UnionFind unionFind(n);
    for (int i = 0; i < n; i++) {
        if (graph.find(i) != graph.end()) {
            int first = i;
            for (auto adj : graph[i]) {
                if (unionFind.find(first) == unionFind.find(adj)) continue;
                unionFind.combine(first, adj);
            }
        }
    }
    int first = 0;
    for (int another = 1; another < n; another++) {
        if (unionFind.find(first) != unionFind.find(another)) {
            ans.push_back(mp(first, another));
            unionFind.combine(first, another);
        }
    }
    return ans;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdin);
#endif
    fast_io;
    int cities, roads;
    cin >> cities >> roads;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < roads; i++) {
        int a; cin >> a;
        int b; cin >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    vector<pair> ans = solve(graph, cities);
    cout << ans.size() << endl;
    for (auto a : ans) {
        cout << a.first + 1 << ' ' << a.second + 1 << '\n';
    }
    cout << endl;
    return 0;
}