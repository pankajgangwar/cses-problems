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

//Problem : https://cses.fi/problemset/task/1145
//Sol : https://cses.fi/problemset/result/1701185
//https://codeforces.com/blog/entry/70018

vector<ll> nums;
int binarySearch(vector<ll>& piles, ll num){
    int low = 0, high = piles.size() - 1;
    while(low <= high){
        int mid = (high + low) / 2;
        int mid_ele = piles[mid];
        if(mid_ele < num){
            low = mid + 1;
        }else{
            if(mid_ele <= 0){
                return mid;
            }
            high = mid - 1;
        }
    }
    return -(low + 1);
}

int longestIncreasingSubsequence(){
    //https://www.cs.princeton.edu/courses/archive/spring13/cos423/lectures/LongestIncreasingSubsequence.pdf
    vector<ll> piles;
    for (ll num : nums){
        int pile = binarySearch(piles, num);
        if (pile < 0){
            pile = ~pile; //Bitwise unary NOT
        }
        if (pile == piles.size()){
            piles.push_back(num);
        }else{
            piles[pile] = num;
        }
    }
    return piles.size();
}

int main() {
    fast_io;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll a = 0;
        cin >> a;
        nums.push_back(a);
    }
    int ans = longestIncreasingSubsequence();
    cout << ans;
    return 0;
}