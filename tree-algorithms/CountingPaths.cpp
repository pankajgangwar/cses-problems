#include <stdio.h>
#include <string.h>
#include <iostream>
#include <unordered_map>
#include <array>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#include <queue>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

// LCA in LogN
//Problem : https://cses.fi/problemset/task/1136/
// Solution: https://cses.fi/problemset/result/1525876/
// Similar : https://codeforces.com/contest/191/problem/C
//Detail explanation: https://cp-algorithms.com/graph/lca.html

const int MAX_NODES = 200001;
const int MAX_DEPTH = 20;
vector<int> tree[MAX_NODES];
int up[MAX_NODES][MAX_DEPTH];
int lvl[MAX_NODES] = {0};
int ans[MAX_NODES] = {0};
int tin[MAX_NODES] = {0}, tout[MAX_NODES] = {0};
int t = 0;
int bal[MAX_NODES];

/* 
Time : O(NlogN)
 */
void binary_lifting(int src, int parent){
    /* 
        2^i = 2^(i-1) + 2^(i-1)
     */
    tin[src] = t++;
    up[src][0] = parent;// node at 2^0 level up
    for(int i = 1; i < MAX_DEPTH; i++){
        if(up[src][i-1] != -1){ // node at 2^(i-1) level up
            int ancestor = up[src][i-1];
            up[src][i] = up[ancestor][i-1];
        }else{
            up[src][i] = -1;
        }
    }
    for(int child : tree[src]){
        if(child != parent){
            lvl[child] = lvl[src] + 1;
            binary_lifting(child, src);
        }
    }
    tout[src] = t++;
}

/*
 Ex: k = 5 : (101) = 2^2 + 2^0
*/
int lift_node(int node, int jump_required) {
    if (jump_required == 0){
       return node;
    } 
    for (int i = MAX_DEPTH - 1; i >= 0 && node != -1; --i) {
        if ((jump_required & (1 << i)) != 0){ // Check if ith bit is set
            node = up[node][i];
        }
    }
    return node;
}

bool isancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}
/* 
Time: O(logN)
 */
int findLCA(int u, int v){
    if(lvl[u] < lvl[v]){
        swap(u, v);
    }
    u = lift_node(u, lvl[u] - lvl[v]);
    if(u == v) return u;
    for (int i = MAX_DEPTH - 1; i >= 0; --i) {
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return lift_node(u, 1);
}

/* 
Time : O(N)
 */
void dfs(int src, int parent){
    for(int child : tree[src]){
        if(child != parent){
            dfs(child, src);
            ans[src] += ans[child];
        }
    }
}

int main(){
    fast_io;
    ll t, n, m, u, v;
    //cin >> t;
    /* 
    while(t-- > 0){

    }
     */
    cin >> n >> m;
    for(int i = 1; i <= n - 1; i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    binary_lifting(1, -1);
    while(m-- > 0){
        ll u, v;
        cin >> u >> v;
        int lca = findLCA(u, v); // Time: O(log N)
        ans[u]++;
        ans[v]++;
        ans[lca]--;
        ans[up[lca][0]]--;
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}

