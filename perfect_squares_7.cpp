#include<bits/stdc++.h>
using namespace std;

int rec_ans(int n)
{
    if(n == 0) return 0;
    int ans = n;
    
    for(int i=1;i<=n;i++)
    {
        
        if(i*i<=n)
        {
            ans = min(ans,1+rec_ans(n-i*i)); 
        }    
    }
return ans;
}
int memo_ans(int n,vector<int> & dp)
{
    if(n == 0) return 0;
    if(dp[n]!=-1) return dp[n];
    int ans = n;
    for(int i=1;i<=n;i++)
    {
        if(i*i<=n)
        ans = min(ans,1+memo_ans(n-i*i,dp));
    }
    dp[n] = ans;
    return dp[n];
    }



int main()
{
    int n = 5;
    vector<int> dp(n+1,-1);
    cout<<memo_ans(n,dp)<<endl;
}