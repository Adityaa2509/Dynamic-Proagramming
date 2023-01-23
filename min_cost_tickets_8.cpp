#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int min_cost_rec(vector<int> days,vector<int>& cost,int ind)
{
    int n = days.size();
    if(ind >= n) return 0;

    //1 day pass;
    int one_day_pass = cost[0] + min_cost_rec(days,cost,ind+1);

    //7 day pass;
    int i;
    for(i = ind ;(i<n) && (days[i]<days[ind]+7);i++);
    int seven_day_pass = cost[1] + min_cost_rec(days,cost,i);

    //30 days pass
    for(i = ind ;(i<n) && (days[i]<days[ind]+30);i++);
    int thirty_day_pass = cost[2] + min_cost_rec(days,cost,i);

return min(one_day_pass,min(seven_day_pass,thirty_day_pass));
}
int min_cost_memo(vector<int> days,vector<int>& cost,int ind,vector<int>& dp)
{    int n = days.size();
    if(ind >= n) return 0;
    if(dp[ind] != -1) return dp[ind];
    //1 day pass;
    int one_day_pass = cost[0] + min_cost_memo(days,cost,ind+1,dp);

    //7 day pass;
    int i;
    for(i = ind ;(i<n) && (days[i]<days[ind]+7);i++);
    int seven_day_pass = cost[1] + min_cost_memo(days,cost,i,dp);

    //30 days pass
    int j;
    for(j = ind ;(j<n) && (days[j]<days[ind]+30);j++);
    int thirty_day_pass = cost[2] + min_cost_memo(days,cost,j,dp);

dp[ind] = min(one_day_pass,min(seven_day_pass,thirty_day_pass));
return dp[ind];

}

int min_cost_tabu(vector<int> days,vector<int>& cost)
{
    vector<int>dp(days.size()+1,INT_MAX);
    dp[days.size()] = 0;
    for(int k =days.size()-1;k>=0;k--)
    {
        
    //1 day pass;
    int one_day_pass = cost[0] + dp[k+1];

    //7 day pass;
    int i;
    for(i = k ;(i<days.size()) && (days[i]<days[k]+7);i++);
    int seven_day_pass = cost[1] + dp[i];

    //30 days pass
    int j;
    for(j = k ;(j<days.size()) && (days[j]<days[k]+30);j++);
    int thirty_day_pass = cost[2] + dp[j];

    dp[k] = min(one_day_pass,min(seven_day_pass,thirty_day_pass));
    }
    return dp[0];
}
int main()
{
    vector<int> days;
    days.push_back(1);
    days.push_back(4);
    days.push_back(6);
    days.push_back(7);
    days.push_back(8);
    days.push_back(20);

    vector<int> cost;
    vector<int>dp(days.size()+1,-1);
    cost.push_back(2);cost.push_back(7);cost.push_back(15);
cout<<min_cost_tabu(days,cost);
}

