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
 
//Problem : https://cses.fi/problemset/task/1713/
//Result: 
 
 
int solve(ll n){
    int count = 0;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0) {
            if(n / i == i){
                count += 1;
            }else{
                count += 2;
            }
        }
    }
    return count;
}
 
int main(){
    fast_io;
    int t;
    cin >> t;
    while(t-- > 0){
        ll n;
        cin >> n;
        cout << solve(n) << '\n';
    }
    return 0;
}