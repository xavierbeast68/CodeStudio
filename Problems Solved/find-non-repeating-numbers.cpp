//* https://www.codingninjas.com/codestudio/problem-details/unique-pair-using-bits_972997
//* https://www.codingninjas.com/codestudio/problems/unique-pair-using-bits_972997?leftPanelTab=1


#include <bits/stdc++.h> 
vector<int> findNonRepeating(vector<int> nums)
{
	// Write Your Code Here.

	int temp = 0;
    for(int i : nums){
        temp = temp ^ i;
    }
    int result = temp;
    int p = 1;
    while((temp & 1) == 0){
        temp >>= 1;
        p++;
    }
    int mask = 1 << (p-1);
    int a = 0, b=0;
    for(int i : nums){
        if(i & mask){
            a ^= i;
        }
        // else {
        //     b ^= i;
        // }
    }
    b = a ^ result;
    vector<int> ans{min(a, b), max(a,b)};
    return ans;
}
