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

/*
* 801. Minimum Swaps To Make Sequences Increasing
* https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
*/
int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int swap[1000] = {1};
        int not_swap[1000] = {0};
        for (int i = 1; i < n; i++){
            swap[i] = not_swap[i] = n;
            if(A[i - 1] < A[i] && B[i - 1] < B[i]){
                swap[i] = swap[i - 1] + 1;
                not_swap[i] = not_swap[i - 1];
            }
            if(A[i - 1] < B[i] && B[i - 1] < A[i]){
                swap[i] = min(swap[i], not_swap[i-1] + 1);
                not_swap[i] = min(swap[i - 1], not_swap[i]);
            }
        }
    return min(swap[n - 1], not_swap[n - 1]);
}

int main(){
    vector<int> A = {0,3,5,8,9};
    vector<int> B = {2,1,4,6,9};
    int res = minSwap(A, B);
    cout<< res;
}