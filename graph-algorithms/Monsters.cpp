#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pair pair<int, int>
#define mp make_pair
using namespace std;

//Problem : https://cses.fi/problemset/task/1194
//Sol : https://cses.fi/problemset/result/1733764
vector<int> visited;
vector<int> parent;
const int max_len = 1000;
char grid[max_len + 1][max_len + 1];

int rows, cols;
vector<pair> monstorsloc;
pair start_user, end_user;

string stepsDir = "RLUD";
int dirs[4][2] = {{0, 1}, {0, -1}, { -1, 0}, {1, 0}};
int previous_step[max_len + 1][max_len + 1];

bool bfs_user(vector<vector<int>>& monster_dist, vector<vector<int>>& user_dist) {
    queue<pair> bfs;
    bfs.push(start_user);

    bool visited[rows][cols] =  { {false} };
    visited[start_user.first][start_user.second] = true;
    int currdist = 1;
    while (!bfs.empty()) {
        int size = bfs.size();
        while (size-- > 0) {
            pair p = bfs.front();
            if (p.first == rows - 1 || p.second == cols - 1 || p.first == 0 || p.second == 0) {
                end_user = p;
                return true;
            }
            bfs.pop();
            for (int i = 0; i < 4; i++) {
                int next_x = p.first + dirs[i][0];
                int next_y = p.second + dirs[i][1];
                if (next_x < 0 || next_x >= rows || next_y < 0 || next_y >= cols ) continue;
                if (visited[next_x][next_y]) continue;
                if (grid[next_x][next_y] == '#' || grid[next_x][next_y] == 'M' ) continue;
                if (monster_dist[next_x][next_y] <= currdist) continue;
                user_dist[next_x][next_y] = currdist;
                previous_step[next_x][next_y] = i;
                visited[next_x][next_y] = true;
                bfs.push(mp(next_x, next_y));
            }
        }
        currdist++;
    }
    return false;
}

void bfs_monster(vector<vector<int>>& monster_dist) {
    queue<pair> bfs;
    for (auto loc : monstorsloc) {
        bfs.push(loc);
    }
    bool visited[rows][cols] = {{false}};
    int currdist = 1;
    while (!bfs.empty()) {
        int size = bfs.size();
        while (size-- > 0) {
            pair p = bfs.front();
            bfs.pop();
            for (int i = 0; i < 4; i++) {
                int next_x = p.first + dirs[i][0];
                int next_y = p.second + dirs[i][1];
                if (next_x < 0 || next_x >= rows || next_y < 0 || next_y >= cols ) continue;
                if (visited[next_x][next_y]) continue;
                if (grid[next_x][next_y] == '#' || grid[next_x][next_y] == 'A') continue;
                pair next = mp(next_x, next_y);
                monster_dist[next_x][next_y] = min(monster_dist[next_x][next_y],
                                                   currdist);
                visited[next.first][next.second] = true;
                bfs.push(next);
            }
        }
        currdist++;
    }
}

void solve(vector<vector<int>>& monster_dist, vector<vector<int>>& user_dist) {
    bfs_monster(monster_dist);
    vector<char> ans;
    if (bfs_user(monster_dist, user_dist)) {
        vector<int> steps;
        while (end_user != start_user) {
            int p = previous_step[end_user.first][end_user.second];
            steps.push_back(p);
            end_user = mp(end_user.first - dirs[p][0], end_user.second - dirs[p][1]);
        }
        reverse(steps.begin(), steps.end());
        cout << "YES" << '\n';
        cout << steps.size() << endl;
        for (int s : steps) {
            cout << stepsDir[s];
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    cin >> rows >> cols;
    vector<vector<int>> monster_dist;
    vector<vector<int>> user_dist;
    for (int i = 0; i < rows; i++) {
        string curr;
        cin >> curr;

        vector<int> monster_row(cols);
        fill(monster_row.begin(), monster_row.end(), INT_MAX);
        monster_dist.push_back(monster_row);

        vector<int> user_row(cols);
        fill(user_row.begin(), user_row.end(), 0);
        user_dist.push_back(user_row);

        for (int j = 0; j < curr.size(); j++) {
            grid[i][j] = curr.at(j);
            if (grid[i][j] == 'M') {
                monstorsloc.push_back(mp(i, j));
                monster_dist[i][j] = 0;
            } else if (grid[i][j] == 'A') {
                start_user = mp(i, j);
            }
        }
    }
    solve(monster_dist, user_dist);
    return 0;
}