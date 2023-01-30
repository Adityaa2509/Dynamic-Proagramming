#include<bits/stdc++.h>
using namespace std;

int rec_uni_ans(int i,int j)
{
    //base condition
    if(i == 0 && j==0) return 1;
    if(i<0 || j<0) return 0;

    //moving condition
    int up = rec_uni_ans(i-1,j);
    int down = rec_uni_ans(i,j-1);
    return up+down;

}

int memo_uni_ans(int i,int j,vector<vector<int>>& dp)
{
    if(i == 0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int up = memo_uni_ans(i-1,j,dp);
    int down = memo_uni_ans(i,j-1,dp);
dp[i][j] = up+down;
return dp[i][j];
}

int tabu_uni_ans(int m,int n)
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
                if(i>0) up = dp[i-1][j];
                if(j>0) down = dp[i][j-1];
                dp[i][j] = up+down; 
            }
        }
    }
    return dp[m-1][n-1];
}
int tabu_space_uni_ans(int m,int n)
{
    vector<int> prev(n,0);
    for(int i=0;i<m;i++)
    {vector<int>temp(n,0);
        for(int j=0;j<n;j++)
        {
            int up=0;
            int down = 0;
            if(i == 0 && j == 0) temp[j] = 1;
            else
            {
                 up = prev[j];
                if(j>0) down = temp[j-1];
                temp[j] = up+down; 
            }

        }
prev=temp;
    }
    return prev[n-1];
}
int main()
{
    int n,m;
    cout<<"Enter m :- ";
    cin>>m;
    cout<<"Enter n :- ";
    cin>>n;
    vector<vector<int>> dp(m,vector<int>(n,-1));
    cout<<"Answer Yo hai Bhai :-- "<<tabu_space_uni_ans(m,n)<<endl;
}