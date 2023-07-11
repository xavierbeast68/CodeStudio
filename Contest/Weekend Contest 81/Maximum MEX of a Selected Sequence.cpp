//* https://www.codingninjas.com/studio/contests/weekend-contest-81/8894371/problems/25460

#include <bits/stdc++.h>
using namespace std;

int findMissingNumber(int n, int k, vector<int> a) {
    // Write your code here.

    vector<int> vec(k, -1);

    for(int i = 0; i < n; i++){
        if(a[i] < k){
            vec[a[i]] = 1;
        }
    }

    for(int i = 0; i < k; i++){
        if(vec[i] == -1){
            return i;
        }
    }
    return k;
}
