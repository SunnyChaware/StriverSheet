#include <bits/stdc++.h> 
bool f(int ind, string s, unordered_set<string> &st, vector<int> &dp){
    if(ind == s.size()){
        return true;
    }
    if(dp[ind]!=-1)return dp[ind];
    for(int i=ind ; i<s.size(); i++){
        if(st.count(s.substr(ind, i+1-ind)) && f(i+1,s,st,dp)){
            return dp[ind] = true;
        }
    }
    return dp[ind] = false;
    }
bool wordBreak(vector < string > & arr, int n, string & s) {
    unordered_set<string> st (arr.begin(), arr.end());
    vector<int>dp(s.size(), -1);
    return f(0,s,st,dp);
}

// tabulation

#include <bits/stdc++.h> 

bool wordBreak(vector < string > & arr, int n, string & s) {
    unordered_set<string> st (arr.begin(), arr.end());
    vector<int>dp(s.size()+1, 0);
    dp[0] = true;
    for(int i=1;i<=s.size();i++){
        for(int j=0;j<i;j++){
            if(dp[j] and st.count(s.substr(j, i-j))){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}
