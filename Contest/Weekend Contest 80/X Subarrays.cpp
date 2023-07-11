//* https://www.codingninjas.com/studio/contests/weekend-contest-80/8875464/problems/25348

long long xSubarrays(int x, vector<int> &a)
{
    // Write your code here

    int n = a.size();
    long long ans = 0;

    int left = 0, right = n-1;

    while(left <= right){
        if(a[left] + a[right] <= x){
            ans += (right-left+1);
            left++;
        }
        else{
            right--;
        }
    }

    return ans;
}