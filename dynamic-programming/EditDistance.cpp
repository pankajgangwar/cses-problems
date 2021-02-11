#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

//Problem : https://cses.fi/problemset/task/1639
//Solution: https://cses.fi/problemset/result/1625769/ 

    int minOfEditOperations(int a, int b, int c){
        return min(min(a,b),c);
    }
    
     int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if(n*m == 0){
            return n + m;
        }

        int dp[n + 1][m + 1];
        
        for(int i = 0; i < n + 1; i++){
            dp[i][0] = i;
        }

        for(int i = 0; i < m + 1; i++){
            dp[0][i] = i;
        }

        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < m + 1; j++){
                if(word1.at(i -1) == word2.at(j -1)){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + minOfEditOperations(dp[i-1][j], dp[i][j-1],dp[i-1][j-1]);
                }
            }   
        }
        return dp[n][m];
    }
// Update the difference to each ancestor node
int main(){
    fast_io;
    string s1, s2;
    cin >> s1 >> s2;
    int ans = minDistance(s1, s2);
    cout << ans;
    return 0;
}