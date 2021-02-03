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

// LCA with Binary search
//https://cses.fi/problemset/task/1688/
//https://cses.fi/problemset/result/1482691/ 

const int MAX_NODES = 200001;
const int MAX_DEPTH = 20;
vector<int> tree[MAX_NODES];
int up[MAX_NODES][MAX_DEPTH];
int lvl[MAX_NODES] = {0};
void binary_lifting(int src, int parent){
    /* 
        2^i = 2^(i-1) + 2^(i-1)
     */
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

/* 
Time: O(logN)
*/
int findLCA(int u, int v){
    if(lvl[u] < lvl[v]){
        swap(u, v);
    }
    u = lift_node(u, lvl[u] - lvl[v]);
    int low = 0, high = lvl[u];
    while(low != high){
        int mid = (low + high) / 2;
        int x1 = lift_node(u, mid);
        int x2 = lift_node(v, mid);
        if(x1 == x2){
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    return lift_node(u, low);
}

int main(){
    fast_io;
    ll t, n, q, employee, boss;
    //cin >> t;
    /* 
    while(t-- > 0){

    }
     */
    cin >> n >> q;
    for(int i = 2; i <= n; i++){
        employee = i;
        cin >> boss;
        tree[boss].push_back(employee);
        tree[employee].push_back(boss);
    }
    binary_lifting(1, -1);
    while(q-- > 0){
        int a, b;
        cin >> a >> b;
        int lca = findLCA(a, b); // Time: O(log^2 N)
        cout << lca << '\n';
    }
    return 0;
}

