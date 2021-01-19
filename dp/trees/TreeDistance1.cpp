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

//Problem : https://cses.fi/problemset/task/1132/
//Submission : https://cses.fi/problemset/result/1497172/
// References: https://usaco.guide/CPH.pdf#page=146 

const int MAX_NODES = 200001;
vector<int> tree[MAX_NODES];
int dist[2][MAX_NODES];

int findMaxDistance(int src, int parent, int d, int a){
    dist[a][src] = d;
    int opt = -1;
    for(int child : tree[src]){
        if(child != parent){
            int curr = findMaxDistance(child, src, d + 1, a);
            if(opt == -1 || dist[a][curr] > dist[a][opt]) {
                opt = curr;
            }
        }
    }
    return opt == -1 ? src : opt;
}

int main(){
    fast_io;
    ll t, n;
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
    int node_a = findMaxDistance(1, 1, 0, 0);
    int node_b = findMaxDistance(node_a, node_a, 0, 0);
    findMaxDistance(node_b, node_b, 0, 1);

    for (int i = 1; i <= n; i++){
        cout << max(dist[0][i], dist[1][i]) << ' ';
    }
    return 0;
}

