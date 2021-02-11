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

//Problem : https://cses.fi/problemset/task/1637
//https://cses.fi/problemset/result/1685298/

int solve(int n) {
    int dp[n + 1];
    dp[0] = 0;
    for (int number = 1; number <= n ; number++) {
        int temp = number;
        dp[number] = 1e6 + 1;//max value
        while(temp != 0){
            int lastDigit = temp % 10;
            temp = temp / 10;
            dp[number] = min(dp[number], dp[number - lastDigit] + 1);
        }
    }
    return dp[n];
}

int main() {
    fast_io;
    int n;
    cin >> n;
    int ans = solve(n);
    cout << ans;
    return 0;
}