// recurssion + memoisation
// tc = o(nxm)
// sc = o(mxn) + o(h)
#include<bits/stdc++.h>
int f(string s, string t, int i, int j,
 vector<vector<int>> &dp){
	if(i<0 or j<0)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	int a=0, b=0;
	if(s[i] == t[j]){
		return dp[i][j] = 1+f(s,t,i-1,j-1,dp);
	}
	return dp[i][j] = max(f(s,t,i-1,j,dp), f(s,t,i,j-1,dp)); 
}
int lcs(string s, string t) {
	int n = s.size();
	int m = t.size();
	vector<vector<int>> dp(n, vector<int> (m, -1));
	return f(s, t, n-1, m-1, dp);
}


// Tabulation method
// tc = o(nxm)
// sc = o(mxn)

#include<bits/stdc++.h>

int lcs(string s, string t) {
	int n = s.size();
	int m = t.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	return dp[n][m];
}


// Tabulation method
// tc = o(nxm)
// sc = o(2m)

#include<bits/stdc++.h>

int lcs(string s, string t) {
	int n = s.size();
	int m = t.size();
	vector<int> prev(m+1, 0), cur(m+1,0);

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				cur[j] = 1+prev[j-1];
			}
			else cur[j] = max(cur[j-1], prev[j]);
		}
		prev = cur;
	}
	return prev[m];
}
