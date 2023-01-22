#include<bits/stdc++.h>
using namespace std;

int rec_ans(vector<int> nums,int tar ,vector<int>& temp)
{
    if(tar == 0)
    {
        for(int i=0;i<temp.size();i++)
        cout<<temp[i]<<" ";
        cout<<endl; return 1;
    }
    if(tar<0) return 0;
    int ans = 0;
    for(int i=0;i<nums.size();i++)
    {
        if(tar>=nums[i])
        {
            temp.push_back(nums[i]);
            ans += rec_ans(nums,tar-nums[i],temp);
            temp.pop_back();
        }

    }
    return ans;
}

int memo_ans(vector<int> nums,int tar,vector<int>& dp,vector<int> & temp )
{
    if(tar == 0)
    {
        for(int i=0;i<temp.size();i++)
        cout<<temp[i]<<" ";
        cout<<endl;
        return 1;
    } 
    
    if(tar<0) return 0;

    if(dp[tar] != -1) return dp[tar];
    int ans = 0;
    for(int i=0;i<nums.size();i++)
    {
        if(tar>=nums[i])
        {
            temp.push_back(nums[i]);
        ans += memo_ans(nums,tar-nums[i],dp,temp);
        temp.pop_back();
        }

    }
    dp[tar] = ans;
    return dp[tar];
}







int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    int target = 4;
    vector<int> dp(target+1,-1);
    vector<int> temp;
    cout<<memo_ans(nums,target,dp,temp)<<endl;
}