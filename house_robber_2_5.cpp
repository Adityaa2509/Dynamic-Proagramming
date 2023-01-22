#include<bits/stdc++.h>
using namespace std;

int ans_memo(vector<int> nums,int ind ,vector<int> &dp)
{
    if(ind == nums.size()-1) return nums[ind];
    if(ind >= nums.size()) return 0;
    if(dp[ind]!=-1) return dp[ind];

    //pick --> robbery done
    int pick = nums[ind] + ans_memo(nums,ind+2,dp);
    //not pick --> robbery not done
    int npick = 0 + ans_memo(nums,ind+1,dp);
    dp[ind] = max(pick,npick);
    return dp[ind];

}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    //nums.push_back(2);
    vector<int> temp1,temp2;
    vector<int> dp1(3,-1);
    vector<int>dp2(3,-1);
    for(int i=0;i<3;i++)
    {
        if(i!=0) temp1.push_back(nums[i]);
        if(i!=nums.size()-1) temp2.push_back(nums[i]);
    }
    int ans1 =ans_memo(temp1,0,dp1);
    int ans2 = ans_memo(temp2,0,dp2);
    cout<<max(ans1,ans2);
}
