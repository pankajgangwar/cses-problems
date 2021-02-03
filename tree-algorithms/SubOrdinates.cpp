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

//Problem : https://cses.fi/problemset/task/1674/
//Result: https://cses.fi/problemset/result/1489386/


const int MAX_NODES = 200001;
vector<int> tree[MAX_NODES];
int sub_ord[MAX_NODES] = {0};
int findSubOrdinates(int src, int parent){
    int cnt = 0;
    for(int child : tree[src]){
        if(child != parent){
            cnt += findSubOrdinates(child, src) + 1;
        }
    }
    sub_ord[src] = cnt;
    return cnt;
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
    for(int i = 2; i <= n; i++){
        employee = i;
        cin >> boss;
        tree[boss].push_back(employee);
        tree[employee].push_back(boss);
    }
    findSubOrdinates(1, -1);
    for (int i = 1; i <= n; i++){
        cout << sub_ord[i] << ' ';
    }
    return 0;
}

