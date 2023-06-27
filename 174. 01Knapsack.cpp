// recurssion + memoisation

#include<bits/stdc++.h>
int f(int ind, vector<int> &values, vector<int> &weights, int w, vector<vector<int>> &dp){
	if(ind == 0){
		if(w >= weights[0])return values[0];
		else return 0;
	}

	if(dp[ind][w]!=-1)
	return dp[ind][w];

	int np = f(ind-1, values, weights, w, dp);
	int p = INT_MIN;
	if(weights[ind]<=w){
		p = values[ind] + f(ind-1, values, weights, w - weights[ind], dp);
	}

	return dp[ind][w]= max(p, np);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n, vector<int> (w+1, -1));
	return f(n-1,values,weights,w,dp);
}

// tabulation

#include<bits/stdc++.h>

int maxProfit(vector<int> &values, vector<int> &weights, int n, int W)
{
	vector<vector<int>> dp(n, vector<int> (W+1, 0));
	for(int i=weights[0];i<=W;i++){
		dp[0][i] = values[0];
	}

	for(int ind = 1; ind<n; ind++){
		for(int w = 1; w<=W ; w++){
			int np = dp[ind-1][w];
			int p = INT_MIN;
			if(weights[ind]<=w){
				p = values[ind] + dp[ind-1][w- weights[ind]];
			}

			dp[ind][w]= max(p, np);
		}
	}
	return dp[n-1][W];
}
