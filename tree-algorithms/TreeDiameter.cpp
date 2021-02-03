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

//Problem : https://cses.fi/problemset/task/1131/
//Submission : https://cses.fi/problemset/result/1489294/


const int MAX_NODES = 200001;
vector<int> tree[MAX_NODES];
int max_diameter = 0;

int diameter(int src, int parent){
    int first_max = 0;
    int sec_max = 0;
    for(int child : tree[src]){
        if(child != parent){
            int curr = diameter(child, src);
            if(first_max < curr){
                sec_max = first_max;
                first_max = curr;
            }else if(sec_max < curr){
                sec_max = curr;
            }
        }
    }
    int longestPathFromRoot = first_max + sec_max; // Top 2 Max lengths
    max_diameter = max(longestPathFromRoot, max_diameter);
    return first_max + 1;
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
    diameter(1, -1);
    cout << max_diameter;
    return 0;
}

