#include<bits/stdc++.h>
using namespace std;
int rec_paths(int n)
{
    if(n == 1||n == 0) return 1;

    if(n<0) return 0;

    return rec_paths(n-1)+rec_paths(n-2)+rec_paths(n-3);
}
int paths_memo(int n ,vector<int> &dp)
{
    if(n==0 || n==1) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    dp[n] = paths_memo(n-1,dp)+paths_memo(n-2,dp)+paths_memo(n-3,dp);
    return dp[n];
}

int paths_tabu(int n)
{
    vector<int>dp(n+1,-1);
    dp[0] = 1;
    for(int i=1;i<=n;i++)
    {
        if(i==1) dp[i]=dp[i-1];
        else if(i == 2) dp[i] = dp[i-1]+dp[i-2];
        else dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}


int main()
{
    int n ;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<paths_tabu(n)<<endl;
    
}