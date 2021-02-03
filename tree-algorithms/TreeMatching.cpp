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

//Problem : https://cses.fi/problemset/task/1130/
//Result: https://cses.fi/problemset/result/1490308/

const int MAX_NODES = 200001;
vector<int> tree[MAX_NODES];
int dp[MAX_NODES][2];

void solve(int src, int parent){
    vector<int> prefix;
    dp[src][0] = dp[src][1] = 0;
    bool leaf = 1;
    for(int child : tree[src]){
        if(child != parent){
            leaf = 0;
            solve(child, src);
        }
    }
    if(leaf) return;
    for(int child : tree[src]){
        if(child != parent){
            prefix.push_back(max(dp[child][0], dp[child][1]));
        }
    }
    int size = (int)prefix.size();
    for(int i = 1; i < size; ++i){
        prefix[i] += prefix[i - 1];
    }
    
    dp[src][0] = prefix[size - 1];
    int c_no = 0;
    for(int child : tree[src]){
        if(child != parent){
            int left = c_no == 0 ? 0 : prefix[c_no - 1];
            int right = c_no == size - 1 ? 0 : prefix[size - 1] - prefix[c_no];
            dp[src][1] = max(dp[src][1], 1 + left + right + dp[child][0]);
            c_no++;
        }
    }
}

int main(){
    fast_io;
    ll t, n, q, employee, boss;
    //cin >> t;
    /* 
    while(t-- > 0){

    }
     */
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    solve(1, -1);
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}

