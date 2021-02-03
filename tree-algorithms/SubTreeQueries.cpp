#include <stdio.h>
#include <string.h>
#include <iostream>
#include <unordered_map>
#include <array>
#include <vector>
#include <set>
#include <queue>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

// LCA in LogN
//Problem : https://cses.fi/problemset/task/1137/
// Solution: 
// Similar : 

const int MAX_NODES = 200001;
const int MAX_DEPTH = 20;
vector<int> tree[MAX_NODES];
int up[MAX_NODES][MAX_DEPTH];
int lvl[MAX_NODES] = {0};
long val[MAX_NODES] = {0};
int tin[MAX_NODES] = {0}, tout[MAX_NODES] = {0};
int t = 0;
/* 
Time : O(N)
 */

void dfs(int src, int parent){
    tin[src] = t++;
    for (int child : tree[src]){
        if (child != parent){
            dfs(child, src);
        }
    }
    tout[src] = t-1;
}

struct BIT {
    vector<long> tree;
    int n;
    BIT(int n) {
        this->n = n;
        tree.assign(n + 2, 0);
    }
    BIT(vector<long> a) : BIT(a.size()) {
        tree = a;
    }
    void update(int i, long value){
        i += 1;
        while (i <= n){
            tree[i] += value;
            i += (i & -i);
        }
    }
    long read(int i){
        i += 1;
        long sum = 0;
        while (i > 0){
            sum += tree[i];
            i -= (i & -i);
        }
        return sum;
    }
    long rangesum(int from, int to){
        return read(to) - read(from - 1);
    }
};

// Update the difference to each ancestor node
int main(){
    fast_io;
    int t, n, m, u, v;
    int q;
    //cin >> t;
    /* 
    while(t-- > 0){

    }
     */
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int value;
        cin >> value;
        val[i] = value;
    }
    
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        u--;v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(0, -1);
        BIT tree (n);
        for(int i = 0; i < n; i++){
            tree.update(tin[i], val[i]);
        }
        for (int i = 0; i < q; i++) {
            int type;
            cin >> type;
            switch (type){
                case 1:{
                    int src;
                    cin >> src;
                    src -= 1;
                    long value;
                    cin >> value;
                    long diff = value - val[src];
                    tree.update(tin[src], diff);
                    val[src] = value;
                }
                break;
                case 2:{
                    int src;
                    cin >> src;
                    src -= 1;
                    long sum = tree.rangesum(tin[src], tout[src]);
                    cout << sum << endl;
                }
                break;
            }
        }
    return 0;
}

