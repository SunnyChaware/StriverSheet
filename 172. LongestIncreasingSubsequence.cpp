// recusrssion + memoization method not cahlling poora poora need more
// optimisation

#include<bits/stdc++.h>
int f(int ind , int prev_ind, int arr[], int n, vector<vector<int>> &dp){
    if(ind == n)return 0;

    if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];

    int b = INT_MIN;
    int a = f(ind+1, prev_ind, arr, n, dp);
    if(prev_ind == -1 or arr[ind]>arr[prev_ind]){
        b =  1+f(ind+1, ind, arr, n, dp);
    }

    return dp[ind][prev_ind+1] = max(a,b);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    return f(0,-1,arr,n,dp);
}


// tabulation o(nXn)
// space o(nXn)
//not cahlling poora poora need more optimisation

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    for(int ind=n-1; ind>=0;ind--){
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
            int b = INT_MIN;
            int a = dp[ind+1][prev_ind+1];
            if(prev_ind == -1 or arr[ind]>arr[prev_ind]){
                b =  1+dp[ind+1][ind+1];
            }

            dp[ind][prev_ind+1] = max(a,b);
        }   
    }
    return dp[0][0];
}


// o(n) the best for lngest increasing subsequence
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    int maxi = INT_MIN;
    vector<int> dp(n, 1);
    for(int i=0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
// still giving tle 
// we need more optimisation

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    int len = 1;
    temp.push_back(arr[0]);
    for(int i=1; i<n; i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), arr[i])-temp.begin();
            temp[ind] = arr[i];
        }
    }
    return len;
}

