// recurssion + moemoisation

#include<bits/stdc++.h>
int f(int ind, int n, vector<int> &price, vector<vector<int>> &dp){
	if(ind == 0){
		return n*price[0];
	}

	if(dp[ind][n]!=-1)return dp[ind][n];

	int np = f(ind-1, n, price, dp);
	int p = INT_MIN;
	int rodlen = ind+1;
	if(rodlen<=n)p = price[ind] + f(ind, n-rodlen, price, dp);

	return dp[ind][n] = max(np, p);
}
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
	return f(n-1, n, price, dp);
}

// tabulation

#include<bits/stdc++.h>

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n+1, vector<int> (n+1,0));
	for(int i=0;i<=n;i++){
		dp[0][i] = i*price[0];
	}

	for(int ind = 1; ind<price.size() ; ind++){
		for(int j = 1; j<=n; j++){
			int np = dp[ind-1][j];
			int p = INT_MIN;
			int rodlen = ind+1;
			if(rodlen<=j)p = price[ind] + dp[ind][j-rodlen];

			dp[ind][j] = max(np, p);
		}
	}
	return dp[n-1][n];
}

