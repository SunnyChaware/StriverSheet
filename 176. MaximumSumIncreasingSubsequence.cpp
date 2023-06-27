// recurssion  + memoisation
// tc -> o(nXm)
// sc -> o(nXm) + auxiliary space

#include <bits/stdc++.h> 
int f(int ind, int prev, int n, vector<int> &rack, vector<vector<int>> &dp){
	if(ind == n){
		return 0;
	}

	if(dp[ind][prev+1]!=-1)
	return dp[ind][prev+1];

	int np = f(ind+1, prev, n, rack, dp);
	int p = INT_MIN;
	if(prev == -1 || rack[prev] < rack[ind]){
		p = rack[ind] + f(ind+1, ind, n, rack, dp);
	}
	return dp[ind][prev+1] = max(np, p);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<vector<int>> dp(n, vector<int> (n+1, -1));
	return f(0, -1, n, rack, dp);
}


// tabulation

#include <bits/stdc++.h> 

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

	for(int ind = n-1; ind>=0 ; ind--){
		for(int prev = n-1; prev >=-1; prev--){
			
			int p = 0;
			if(prev == -1 || rack[prev] < rack[ind]){
				p = rack[ind] + dp[ind+1][ind+1];
			}
			p = max(p, dp[ind+1][prev+1]);
			dp[ind][prev+1] = p;
		}
	}
	return dp[0][0];
}
