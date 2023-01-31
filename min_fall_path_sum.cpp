#include<bits/stdc++.h>
using namespace std;

int rec_ans(int i,int j,vector<vector<int>>& grid,int n)
{
    if(j<0 || j>=n) return 1e8;
    if(i==0) return grid[i][j];

    long long int a = grid[i][j] + rec_ans(i-1,j,grid,n);
   long long int b = grid[i][j] + rec_ans(i-1,j-1,grid,n);
   long long int c = grid[i][j] + rec_ans(i-1,j+1,grid,n);
    return min(a,min(b,c));
}

int memo_ans(int i,int j,vector<vector<int>> grid,int n,vector<vector<int>>& dp)
{
    if(j<0 || j>=n) return 1e8;
    if(i == 0) return grid[0][j];
    //memoization step
    if(dp[i][j]!=-1) return dp[i][j];

    int a = grid[i][j] + memo_ans(i-1,j,grid,n,dp);
    int b = grid[i][j] + memo_ans(i-1,j-1,grid,n,dp);
    int c = grid[i][j] + memo_ans(i-1,j+1,grid,n,dp);

    return min(a,min(b,c)); 
    
}
int tabu_ans(vector<vector<int>> grid,int n)
{
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    dp[0][i] = grid[0][i];

for(int i=1;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
       long long int b=grid[i][j];
       long long int c =grid[i][j];
        long long int a = grid[i][j]+dp[i-1][j];
        if(j-1>=0)  b += dp[i-1][j-1];
        else b+=1e8;
        if(j+1<n) c += dp[i-1][j+1];
        else c+=1e8;
        dp[i][j] = min(a,min(b,c));
    }


}
int mini = dp[n-1][0];
for(int i=1;i<n;i++)
mini = min(mini,dp[n-1][i]);
return mini;
}

int main()
{
    int n;
    cout<<"Enter n :- ";
    cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>grid[i][j];
    }
    
    //vector<vector<int>> dp(n,vector<int>(n,-1));
    
    int ans = tabu_ans(grid,n);
    cout<<ans<<endl;
}