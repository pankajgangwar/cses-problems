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

//Problem : https://cses.fi/problemset/task/1717
//Sol : https://cses.fi/problemset/result/1837696

const int N = 1e6;
const int mod = 1e9 + 7;

int inverseOfNumber[N + 1];
void calculateInverse() {
    inverseOfNumber[0] = inverseOfNumber[1] = 1;
    for (int i = 2; i <= N; i++) {
        inverseOfNumber[i] = inverseOfNumber[mod % i] * (mod - mod / i) % mod;
    }
}
int inverseOfFact[N + 1];
void calculateFactorialInv() {
    inverseOfFact[0] = inverseOfFact[1] = 1;
    for (int i = 2; i <= N; i++) {
        inverseOfFact[i] = (inverseOfNumber[i] % mod * inverseOfFact[i - 1] % mod) % mod;
    }
}
int fact[N + 1];
void factorial() {
    fact[0] = 1;
    // n! = n * (n - 1)!
    for (int i = 1; i <= N; i++) {
        fact[i] = (i * fact[i - 1]) % mod;
    }
}

/*
Ways to distribute m mangoes to n people :
1) m identical and n identical:
    (m+n-1)!/((n-1)!*(m)!) -> (m + n - 1) C (n-1)
2) m unique and n identical:
    (m+n-1)!/((n-1)! -> (m + n - 1) C (n-1) * m!
3) m identical and n unique:
    (m+n-1)!/m! -> (m + n - 1) C (n-1) * (n-1)!
4) Both unique
    (m+n-1)! -> (m + n - 1) C (n-1) * (n-1)! * m!
*/

/*
Number of dearangments for n different objects
https://brilliant.org/wiki/derangements

!N = N![1 - 1/1! + 1/2! - 1/3! + 1/4! ... 1/N! ]

*/
int32_t main() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    clock_t tStart = clock();
#endif
    calculateInverse();
    calculateFactorialInv();
    factorial();

    int n;
    cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0 ) {
            ans = (ans + inverseOfFact[i]) % mod;
        } else {
            ans = (ans - inverseOfFact[i] + mod) % mod;
        }
    }
    ans = (ans * fact[n]) % mod;
    cout << ans << endl;
#ifndef ONLINE_JUDGE
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}