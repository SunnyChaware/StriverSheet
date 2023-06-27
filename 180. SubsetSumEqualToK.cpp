#include <bits/stdc++.h> 
bool f(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0)
        return true;
    
    if(ind == 0)
        return arr[0] == target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    bool notTaken = f(ind-1,target,arr,dp);
    
    bool taken = false;
    if(arr[ind]<=target)
        taken = f(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken||taken;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(1001, vector<int>(1001, -1));
    return f(n-1, k, arr, dp);
}

// tabulation

#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(1001, vector<bool>(1001, false));

    for(int i=0;i<n;i++)dp[i][0] = true;
    dp[0][arr[0]] = true;

    for(int ind =1; ind<n;ind++){
        for(int tar = 1; tar <= k; tar++){
            bool nt = dp[ind-1][tar];
            bool t = false;
            if(arr[ind]<=tar){
                t = dp[ind-1][tar-arr[ind]];
            }

            dp[ind][tar] = (nt or t);
        }
    }

    return dp[n-1][k];
}
