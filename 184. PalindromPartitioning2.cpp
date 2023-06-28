#include <bits/stdc++.h> 
bool is(int l, int r, string s){
    while(l<r){
        if(s[l++]!=s[r--])return false;
    }
    return true;
}
int f(int ind, int n, string &s, vector<int> &dp)
{
    if(ind == n)return 0;

    if(dp[ind]!=-1)return dp[ind];

    int mini = INT_MAX;
    for(int i=ind;i<n;i++){
        if(is(ind, i, s)){
            int cost = 1+f(i+1,n,s, dp);
            mini = min(cost, mini);
        }
    }
    return dp[ind] = mini;
}
int palindromePartitioning(string s) {
    int n = s.size();
    vector<int> dp(n+1, -1);
    return f(0, n, s, dp)-1;
}


// tabulation
#include <bits/stdc++.h> 
bool is(int l, int r, string s){
    while(l<r){
        if(s[l++]!=s[r--])return false;
    }
    return true;
}

int palindromePartitioning(string s) {
    int n = s.size();
    vector<int> dp(n+1, 0);
    for(int ind=n-1;ind>=0;ind--){
        int mini = INT_MAX;
        for(int i=ind;i<n;i++){
            if(is(ind, i, s)){
                int cost = 1+dp[i+1];
                mini = min(cost, mini);
            }
        }
        dp[ind] = mini;
    }
    return dp[0]-1;
}
