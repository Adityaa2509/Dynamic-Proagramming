#include<bits/stdc++.h>
using namespace std;

int rec_ans(int i,int j,int n,vector<vector<int>> tri)
{
    if(i == n-1) return tri[i][j];

    int d = tri[i][j] + rec_ans(i+1,j,n,tri);
    int dg = tri[i][j] + rec_ans(i+1,j+1,n,tri);
    return min(d,dg);
}
int memo_ans(int i,int j,int n,vector<vector<int>> tri,vector<vector<int>>& dp)
{
    if(i == n-1) return tri[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int d = tri[i][j] + memo_ans(i+1,j,n,tri,dp);
    int dg = tri[i][j] + memo_ans(i+1,j+1,n,tri,dp);
    dp[i][j] = min(d,dg);
    return min(d,dg);
}
int tabu_ans(int n,vector<vector<int>> tri)
{
    vector<vector<int>>dp(n,vector<int>(n,-1));
    for(int j=0;j<n;j++)
    {
dp[n-1][j] = tri[n-1][j];
    }

for(int i=n-2;i>=0;i--)
{
    for(int j=i;j>=0;j--)
    {
        int d = tri[i][j]+dp[i+1][j];
        int dg=tri[i][j]+dp[i+1][j+1];
    dp[i][j]=min(d,dg);
    }
}

return dp[0][0];
}
int main()
{
    vector<vector<int>> tri={{2},{3,4},{6,5,7},{4,1,8,3}};
    int n=tri.size();
 vector<vector<int>> dp(n,vector<int>(n,-1));   
    cout<<tabu_ans(n,tri);
}