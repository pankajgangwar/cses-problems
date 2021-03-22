#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <map>
#include <bits/stdc++.h>
#define int long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pair pair<int, int>
#define mp make_pair
using namespace std;

//Problem : https://cses.fi/problemset/task/2165
//Sol : https://cses.fi/problemset/result/1863967

vector<pair> moves;
void dfs(int disk, int from_disk, int aux_disk, int to_disk) {
    if (disk == 1) {
        moves.push_back(mp(from_disk, to_disk));
        return;
    }
    dfs(disk - 1, from_disk, to_disk, aux_disk);
    moves.push_back(mp(from_disk, to_disk));
    dfs(disk - 1, aux_disk, from_disk, to_disk);
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    int n;
    cin >> n;
    dfs(n, 1, 2, 3);
    cout << moves.size() << '\n';
    for (auto curr : moves) {
        cout << curr.first << ' ' << curr.second << '\n';
    }
    cout << endl;
    return 0;
}