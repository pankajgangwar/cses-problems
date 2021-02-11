#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

//Problem : https://cses.fi/problemset/task/1636
//

int solve(int amount, vector<int>& coins) {
    int n = coins.size();
    int dp[n + 1][amount + 1];
    int mod = (int) 1e9 + 7;
    for (int i = 0; i <= n ; i++) {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= amount; j++) {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (j - coins[i - 1] >= 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            dp[i][j] %= mod;
        }
    }
    return dp[n][amount];
}

int main() {
    fast_io;
    int n, target;
    cin >> n >> target;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int ans = solve(target, coins);
    cout << ans;
    return 0;
}