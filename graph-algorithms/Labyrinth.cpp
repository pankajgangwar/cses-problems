#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include <queue>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pair pair<int, int>
#define mp make_pair
using namespace std;

//Problem : https://cses.fi/problemset/task/1158
//Sol : https://cses.fi/problemset/result/1717966/

int n, m;
char grid[1000][1000];
bool visited[1000][1000];
int previousStep[1000][1000];

string stepsDir = "RLUD";
int dirs[4][2] = {{0, 1}, {0, -1}, { -1, 0}, {1, 0}};

void bfs(int rows, int cols, pair start) {
    queue<pair> bfs;
    bfs.push(start);
    visited[start.first][start.second] = true;
    while (!bfs.empty()) {
        int size = bfs.size();
        while (size-- > 0) {
            pair curr = bfs.front();
            bfs.pop();
            for (int i = 0; i < 4; i++) {
                int next_x = dirs[i][0] + curr.first;
                int next_y = dirs[i][1] + curr.second;
                if (next_x < 0 || next_x >= rows || next_y < 0 || next_y >= cols ) continue;
                if (grid[next_x][next_y] == '#') continue;
                if (visited[next_x][next_y]) continue;
                visited[next_x][next_y] = true;
                pair next = mp(next_x, next_y);
                previousStep[next_x][next_y] = i;
                bfs.push(next);
            }
        }
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdin);
#endif
    fast_io;
    int rows, cols;
    cin >> rows >> cols;
    pair start, end;
    for (int i = 0; i < rows; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < row.size(); j++) {
            grid[i][j] = row.at(j);
            if (grid[i][j] == 'A') {
                start = mp(i, j);
            } else if (grid[i][j] == 'B') {
                end = mp(i, j);
            }
        }
    }
    bfs(rows, cols, start);
    if (!visited[end.first][end.second]) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<int> steps;
        while (end != start) {
            int p = previousStep[end.first][end.second];
            steps.push_back(p);
            end = mp(end.first - dirs[p][0], end.second - dirs[p][1]);
        }
        reverse(steps.begin(), steps.end());
        cout << steps.size() << endl;
        for (int s : steps) {
            cout << stepsDir[s];
        }
        cout << endl;
    }
    return 0;
}