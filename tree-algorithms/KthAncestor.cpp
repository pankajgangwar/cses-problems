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

// Binary lifting
//https://cses.fi/problemset/task/1687/

const int MAX_NODES = 200001;
const int MAX_DEPTH = 20;
vector<int> tree[MAX_NODES];
int up[MAX_NODES][MAX_DEPTH];
/* 
Time : O(NlogN)
 */
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
            binary_lifting(child, src);
        }
    }
}

/*
 Ex: k = 5 : (101) = 2^2 + 2^0
 Time : O(logN)
*/
int answer_query(int node, int k) {
    if (k == 0){
       return node;
    } 
    for (int i = MAX_DEPTH; i >= 0 && node != -1; --i) {
        if ((k & (1 << i)) == 1){ // Check if ith bit is set
            node = up[node][i];
        }
    }
    return node;
}

int query_dfs(int node, int jump_required) {
    if (node == -1 || jump_required == 0){
       return node;
    }
    for (int i = MAX_DEPTH; i >= 0 ; --i) { // largest possible jump
        if ((jump_required >= (1 << i))){
            return query_dfs(up[node][i], jump_required - (1 << i));
        }
    }
    return node;
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
        int node, level;
        cin >> node >> level;
        int ans = answer_query(node, level);
        cout << ans << '\n';
    }
    return 0;
}

