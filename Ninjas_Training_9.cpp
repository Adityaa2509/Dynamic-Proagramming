#include<bits/stdc++.h>
using namespace std;

int max_merit_score_rec(vector<vector<int>> arr,int days,int last)
{
    if(days == 0)
    {
        int maxi = 0;
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            maxi = max(maxi,arr[0][i]);
        }
    return maxi;
    }
    int maxi = 0;
    int points = 0;
    for(int i=0;i<3;i++)
    {
        if(i!=last)
        {
            points = arr[days][i] + max_merit_score_rec(arr,days-1,i);
            maxi = max(points,maxi);
        }
    }
return maxi;
}

int max_merit_score_memo(vector<vector<int>> arr,int days,int last,vector<vector<int>>& dp)
{
    if(days == 0)
    {
        int maxi = 0;
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            maxi = max(maxi,arr[0][i]);
        }
    return maxi;
    }
    if(dp[days][last]!=-1) return dp[days][last];
    int maxi = 0;
    int points = 0;
    for(int i=0;i<3;i++)
    {
        if(i!=last)
        {
            points = arr[days][i] + max_merit_score_rec(arr,days-1,i);
            maxi = max(points,maxi);
        }
    }
    dp[days][last] = maxi;
return maxi;
}


int main()
{
    
    int n;
    
    cout<<"Enter the no of days :- ";
    cin>>n;
    cout<<"Enter training points for each day : -"<<endl;
    vector<vector<int>> arr(n,vector<int>(3));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
            

        }
    }
    vector<vector<int>> dp(n,vector<int>(4,-1));
cout<<max_merit_score_memo(arr,n-1,3,dp);
}