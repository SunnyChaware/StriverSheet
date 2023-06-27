// recurssion + memoization
#include<bits/stdc++.h>
int f(string &s, string &t, int i, int j, vector<vector<int>> &dp){
    if(i==0)return j;
    if(j==0)return i;

    if(dp[i][j]!=-1)return dp[i][j];

    if(s[i-1]==t[j-1])
        return  dp[i][j] = f(s,t,i-1,j-1, dp);

    else {
        int a = f(s, t, i - 1, j - 1, dp);
        int b = f(s, t, i - 1, j, dp);
        int c = f(s, t, i, j - 1, dp);

        return dp[i][j] = 1+min({a,b,c});
    }
}
int editDistance(string s, string t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    return f(s,t,n,m,dp);
}

// Tbulation
#include<bits/stdc++.h>

int editDistance(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i=0;i<=n;i++)dp[i][0] = i;
    for(int j=0;j<=m;j++)dp[0][j] = j;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1+min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]});
        }
    }
    return dp[n][m];
}
