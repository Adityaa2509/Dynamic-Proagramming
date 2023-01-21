#include<iostream>
#include<vector>
using namespace std;
int rec_fibo(int n)
 {
    //bakwaas approach
    if(n == 0|| n==1)
    return n;
    return rec_fibo(n-1)+rec_fibo(n-2);
 }
 int fibo_memo(int n,vector<int>&dp)
 {
    cout<<"Hello "<<"-> "<<n<<endl;
    if(n==0||n==1) return n;
    if(dp[n]!=-1) return dp[n];
    dp[n] = fibo_memo(n-1,dp)+fibo_memo(n-2,dp);

 return dp[n];
 }
 int main()
 {
    int n;
    cin>>n;
   vector<int>dp(n+1,-1);
    cout<<fibo_memo(n,dp);
 }