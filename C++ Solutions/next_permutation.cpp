//* https://www.codingninjas.com/codestudio/problem-details/next-permutaion_893046
//* https://www.codingninjas.com/codestudio/problems/next-permutaion_893046?leftPanelTab=1
//* https://www.youtube.com/watch?v=LuLCLgMElus

#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int N)
{
    //  Write your code here.

    if (N == 1)
        {
            return permutation;
        }

        int i = N - 2, ind1 = -1;
        while (i >= 0 && ind1 == -1)
        {
            if (permutation[i] < permutation[i + 1])
            {
                ind1 = i;
            }
            i--;
        }
        if (ind1 == -1)
        {
            reverse(begin(permutation), end(permutation));
            return permutation;
        }

        i = N - 1;
        int ind2 = -1;
        while (i >= 0 && ind2 == -1)
        {
            if (permutation[i] > permutation[ind1])
            {
                ind2 = i;
            }
            i--;
        }

        // swapping->
        int temp = permutation[ind1];
        permutation[ind1] = permutation[ind2];
        permutation[ind2] = temp;

        reverse(permutation.begin() + (ind1 + 1), permutation.end());

        return permutation;
}