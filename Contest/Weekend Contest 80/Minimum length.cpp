//* https://www.codingninjas.com/studio/contests/weekend-contest-80/8875464/problems/25577

int minimumLength(vector<int> &a, vector<int> &b){
    // Write your code here

    int n = a.size();
    int left = 0, right = n - 1;

    while(left < right){
        if(a[left] == b[left]){
            left++;
        }
        if(a[right] == b[right]){
            right--;
        }

        if(a[left] != b[left] && a[right] != b[right]){
            break;
        }
    }

    if(right <= left){
        return 0;
    }
    return right - left + 1;
}




/*
* Editorial->
Approach:-

To select the subarray, we have to take care that for all elements that are different at the same index in both arrays should come in that subarray.
We can take a subarray that starts and ends with the first and last index such that elements that are different at the same index in both arrays.

Algorithm:-
Initialize 'l' with 'N'+1 and 'r' with -1.
Iterate using 'i' from 1 to 'N':
if('A[i]'!='B[i]'):
'l'=min('l','i').
'r'=max('r','i').
if('r'==-1):
Return 0.
else:
Return 'r'-'l'+1.
Time Complexity
O(N), where 'N' is the length of the array.

We are traversing from 1 to 'N', and the complexity associated with this is O(N). hence, the overall time complexity is of the order O(N).  

Space Complexity
O(1).

We are using constant extra space. So the Space Complexity is O(1).

//* Code->

> Time Complexity: O(N)
> Space Complexity: O(1)

where 'N' is the length of the array.

int minimumLength(vector<int> &a, vector<int> &b)
{
    int n = a.size();

    // Initializing 'l' with 'N'+1 and 'r' with -1.
    int l = n + 1, r = -1;

    // Calculating length of subarray.
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            l = min(l, i);
            r = max(r, i);
        }
    }

    // We are returning the answer here.
    if (r == -1)
    {
        return 0;
    }
    else
    {
        return r - l + 1;
    }
}

*/