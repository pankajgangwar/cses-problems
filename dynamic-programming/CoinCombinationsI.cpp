#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

//Problem : https://cses.fi/problemset/task/1635
//https://cses.fi/problemset/result/1681543
 
int solve(int amount, vector<int>& coins) {
    int n = coins.size();
    int dp[amount + 1] = {0};
    dp[0] = 1;
    int mod = (int) 1e9 + 7;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0 ) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
            }
        }
    }
    return dp[amount];
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