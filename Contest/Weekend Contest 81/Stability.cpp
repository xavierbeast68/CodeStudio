//* https://www.codingninjas.com/studio/contests/weekend-contest-81/8894371/problems/25015

#include <bits/stdc++.h>
using namespace std;

int isPossibleToDivide(int n, int k, vector<int> &a) {
    // Write your code here.

    unordered_map<int,int> mp;
    int maxF = 0;
    for(int i = 0; i < n; i++){
        mp[a[i]]++;

        maxF = max(maxF, mp[a[i]]);
    }

    return ((k * maxF) <= n ? 1 : 0);
}