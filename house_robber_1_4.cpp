#include<bits/stdc++.h>
using namespace std;

int rec_ans(vector<int> arr,int ind)
{
if(ind == arr.size()-1) return arr[ind];
if(ind >= arr.size()) return 0;


//picking the element
int pick = arr[ind]+rec_ans(arr,ind+2);

//not picking the elemnt
int notpick = 0 + rec_ans(arr,ind+1);

return max(pick,notpick);

}

int memo_ans(vector<int> nums,int ind,vector<int>& dp)
{
    if(ind == nums.size()-1) return nums[ind];
    if(ind >= nums.size()) return 0;
    if(dp[ind]!=-1) return dp[ind];

    int pick = nums[ind]+memo_ans(nums,ind+2,dp);
    int notpick = 0 + memo_ans(nums,ind+1,dp);
    dp[ind] = max(pick,notpick);
    return dp[ind];
}
int tabu_ans_mod(vector<int> nums)
{
    int prev = nums[0];
    int prev2 = 0;
    for(int i=1;i<nums.size();i++)
    {
        int pick = nums[i];
        if(i>1) pick += prev2;
        int npick = 0 + prev;
        int curr = max(pick,npick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(1);
    vector<int>dp(5,-1);
    cout<<tabu_ans_mod(arr);
}