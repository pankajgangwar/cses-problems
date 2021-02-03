#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

//Problem : https://cses.fi/problemset/task/1138/
//Solution: https://cses.fi/problemset/result/1625769/ 

const int MAX_NODES = 200001;
vector<int> tree[MAX_NODES];
ll ans[MAX_NODES] = {0};
long val[MAX_NODES] = {0};
int tin[MAX_NODES] = {0}, tout[MAX_NODES] = {0};
int t = 0;
set<int> colors[MAX_NODES];

void dfs(int src, int parent){
    for (int child : tree[src]){
        if (child != parent){
            dfs(child, src);
            if(colors[child].size() > colors[src].size()){
                swap(colors[src], colors[child]);
            }
            for(int col : colors[child]){
                colors[src].insert(col);
            }
            colors[child].clear();
        }
    }
    ans[src] = colors[src].size();
}

// Update the difference to each ancestor node
int main(){
    fast_io;
    int t, n, m, u, v;
    int q;
    cin >> n;
    for(int i = 0; i < n; i++){
        int value;
        cin >> value;
        colors[i].insert(value);
    }
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        u--;v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}