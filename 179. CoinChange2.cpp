// recurssion + memoization
#include<bits/stdc++.h>
long f(int ind, int value, int coins[], vector<vector<long>>&dp){
    if(ind == 0){
        if((value % coins[0])==0)return 1;
        else return 0;
    }

    if(dp[ind][value]!=-1)return dp[ind][value];

    long np = f(ind-1,value,coins, dp);
    long p = 0;
    if(value>=coins[ind]){
        p = f(ind, value-coins[ind], coins, dp);
    }

    return dp[ind][value] = p+np;
}
long countWaysToMakeChange(int *coins, int n, int value)
{
    vector<vector<long>> dp(n, vector<long> (value+1, -1));
    return f(n-1, value, coins, dp);
}

//tabulation

#include<bits/stdc++.h>

long countWaysToMakeChange(int *coins, int n, int value)
{
    vector<vector<long>> dp(n, vector<long> (value+1, 0));
    for(int i=0;i<=value;i++){
        dp[0][i] = ((value % coins[0])==0);
    }

    for(long long ind=1;ind<n;ind++){
        for(long long j = 0; j<= value ; j++){
            long long np = dp[ind-1][j];
            long long p = 0;
            if(coins[ind]<=j){
                p = dp[ind][j-coins[ind]];
            }
            dp[ind][j] = p+np;
        }
    }
    return dp[n-1][value];
}
