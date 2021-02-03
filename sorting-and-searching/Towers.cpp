#include <stdio.h>
#include <string.h>
#include <iostream>
#include <unordered_map>
#include <array>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#include <queue>
using namespace std;
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

vector<ll> nums;

/*  Towers
Problem: https://cses.fi/problemset/task/1073/
Solution: https://cses.fi/problemset/result/1519815/
 */
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

int minimumPossibleTowers(){
    //https://www.cs.princeton.edu/courses/archive/spring13/cos423/lectures/LongestIncreasingSubsequence.pdf
    vector<ll> piles;
    for (ll num : nums){
        int pile = binarySearch(piles, num);
        if (pile < 0){
            pile = ~pile; //Bitwise unary NOT
        }
        if (pile == piles.size() || (piles[piles.size() - 1] == num)){
            piles.push_back(num);
        }
        else if (piles[pile] == num && pile + 1 < piles.size()){
            piles[pile + 1] = num;
        }
        else{
            piles[pile] = num;
        }
    }
    return piles.size();
}

int main(){
    fast_io;
    ll t, n, q;
    //cin >> t;
    /* 
    while(t-- > 0){

    }
     */
    cin >> n;
    for(int i = 0; i < n; i++){
        ll size = 0;
        cin >> size;
        nums.push_back(size);
    }
    int res = minimumPossibleTowers();
    cout << res;
    return 0;
}

