#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include <chrono>
#define int long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

//Problem : https://cses.fi/problemset/task/1096
//Sol : https://cses.fi/problemset/result/

const int N = 1e6;
const int mod = 1e9 + 7;

/*
TLE
*/
int fun(int n) {
    if (n <= 0 ) return 1;
    int res = 0;
    for (int i = 1; i <= 6; i++) {
        if (n - i >= 0 ) {
            res = res + fun(n - i);
        }
    }
    return res;
}

int memo[N + 1];
int func_memo(int n) {
    if (n <= 0 ) return 1;
    if (memo[n] != -1) return memo[n];
    int res = 0;
    for (int i = 1; i <= 6; i++) {
        if (n - i >= 0 ) {
            res = res + fun(n - i);
        }
    }
    return memo[n] = res;
}

int func_dp(int n) {
    int dp[n + 1];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] = (dp[i] % mod + dp[i - j] % mod) % mod;
            }
        }
    }
    return dp[n] % mod;
}


/* struct Matrix {
        vector< vector<int> > mat; // the contents of matrix as a 2D-vector
        int n_rows, n_cols; // number of rows and columns

        Matrix(vector< vector<int> > values): mat(values), n_rows(values.size()),
        n_cols(values[0].size()) {}

        static Matrix identity_matrix(int n) {
            // Return I_n - the identity matrix of size n.
            // This function is static, because it creates a new Matrix instance
            vector< vector<int> > values(n, vector<int>(n, 0));
            for(int i = 0; i < n; i++)
                values[i][i] = 1;
            return values;
        }

        Matrix operator*(const Matrix &other) const {
            int n = n_rows, m = other.n_cols;
            vector< vector<int> > result(n_rows, vector<int>(m, 0));
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++) {
                    for(int k = 0; k < n_cols; k++) {
                        result[i][j] = (result[i][j] + mat[i][k] * 1ll * other.mat[k][j]) % mod;
                    }
                }
            // Multiply matrices as usual, then return the result as the new Matrix
            return Matrix(result);
        }

        inline bool is_square() const {
            return n_rows == n_cols;
        }
 };

Matrix M_powers[55];
void        (Matrix M) {
    assert(M.is_square());
    M_powers[0] = M;

    for(int i = 1; i < 55; i++)
        M_powers[i] = M_powers[i - 1] * M_powers[i - 1];
}

Matrix fast_exponentiation_with_precalc(int power) {
    Matrix result = Matrix::identity_matrix(M_powers[0].mat.size());
    int pointer = 0;
    while(power) {
        if(power & 1)
            result = result * M_powers[pointer];
        pointer++;
        power >>= 1;
    }
    return result;
}*/

vector<vector<int>> mul(vector<vector<int>> x, vector<vector<int>> y) {
    vector<vector<int>> r(6, vector<int>(6));
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                r[i][j] = (r[i][j] + ((x[i][k] * y[k][j]) % mod)) % mod;
            }
        }
    }
    return r;
}

vector<vector<int>> modpow(vector<vector<int>> a, int n) {
    if (n == 0) {
        vector<vector<int>> r(6, vector<int> (6));
        for (int i = 0; i < 6; i++) {
            r[i][i] = 1;
        }
        return r;
    }
    vector<vector<int>> u = modpow(a, n / 2);
    u = mul(u, u);
    if (n % 2 == 1) u = mul(u, a);
    return u;
}

vector<vector<int>> expo_power(vector<vector<int>> a, int n) {
    vector<vector<int>> r(6, vector<int> (6));
    for (int i = 0; i < 6; i++) {
        r[i][i] = 1;
    }
    while (n > 0) {
        if (n % 2 == 1) {
            r = mul(r, a);
        }
        a = mul(a, a);
        n = n >> 1;
    }
    return r;
}

int32_t main() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    clock_t tStart = clock();
#endif
    int n;
    cin >> n;
    vector<vector<int>> a(6, vector<int> (6));

    for (int i = 0; i < 5; i++) {
        a[i][i + 1] = 1;
    }
    for (int i = 0; i < 6; i++) {
        a[5][i] = 1;
    }
    vector<vector<int>> ans = expo_power(a, n);
    cout << ans[5][5] << endl;

#ifndef ONLINE_JUDGE
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}