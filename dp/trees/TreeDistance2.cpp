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

//Problem : https://cses.fi/problemset/task/1133/
//Submission : https://cses.fi/problemset/result/1519174/

const int MAX_NODES = 200001;
vector<int> tree[MAX_NODES];
ll subTreeAns[MAX_NODES];
ll subTreeSize[MAX_NODES];
ll ans[MAX_NODES];

void preprocessing(int src, int parent){
    int numOfNodes = 1;
    ll subTreeTotal = 0;
    for(int child : tree[src]){
        if(child != parent){
            preprocessing(child, src);
            subTreeTotal += subTreeSize[child] + subTreeAns[child];
            numOfNodes += subTreeSize[child];
        }
    }
    subTreeAns[src] = subTreeTotal;
    subTreeSize[src] = numOfNodes;
}

void solve(int src, int parent, ll partialAns, int& totalNodes){
    ans[src] = subTreeAns[src] + partialAns + (totalNodes - subTreeSize[src]);
    for(int child : tree[src]){
        if(child != parent){
            solve(child, src, ans[src] - (subTreeAns[child] + subTreeSize[child]), totalNodes);
        }
    }
}

int main(){
    fast_io;
    int t, n;
    //cin >> t;
    /* 
    while(t-- > 0){

    }
     */
    cin >> n;
    int a, b;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    preprocessing(1, 0);
    solve(1, 0, 0, n);
    for (int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}

