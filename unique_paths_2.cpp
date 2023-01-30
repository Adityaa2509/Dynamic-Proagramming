#include<bits/stdc++.h>
using namespace std;

int rec_ans(vector<vector<int>> grid,int i,int j)
{
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    int up=0,left=0;
    if(i-1>=0 && grid[i-1][j]!=1) up = rec_ans(grid,i-1,j);
    if(j-1>=0 && grid[i][j-1]!=1) left =rec_ans(grid,i,j-1);
    return left+up;
}

int memo_ans(vector<vector<int>> grid,int i,int j,vector<vector<int>>& dp)
{
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=0,left=0;
    if(i-1>=0 && grid[i-1][j]!=1) up = rec_ans(grid,i-1,j);
    if(j-1>=0 && grid[i][j-1]!=1) left =rec_ans(grid,i,j-1);
    dp[i][j]=left+up;
    return left+up;
}
int tabu_ans(int m,int n,vector<vector<int>> grid)
{
    vector<vector<int>> dp(m,vector<int>(n,-1));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int up=0;
            int down = 0;
            if(i == 0 && j == 0) dp[i][j] = 1;
            else
            {
                if(i>0 && grid[i-1][j]!=1) up = dp[i-1][j];
                if(j>0 && grid[i][j-1]!=1) down = dp[i][j-1];
                dp[i][j] = up+down; 
            }
        }
    }
    return dp[m-1][n-1];
}
int main()
{
    int m,n;
    cout<<"Enter m:- ";
    cin>>m;
    cout<<"Enter n :- ";
    cin>>n;
    vector<vector<int>> grid(m,vector<int>(n));
    cout<<"Enter grid elements :- "<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        cin>>grid[i][j];
    }
    vector<vector<int>>dp(m,vector<int>(n,-1));
    if(grid[m-1][n-1]==1) cout<<"0"<<endl;
    else cout<<tabu_ans(m,n,grid);

}