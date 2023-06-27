// recurssion + memoization

#include <bits/stdc++.h> 
int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i==0 and j==0)return grid[i][j];

    if(dp[i][j]!=-1)return dp[i][j];

    int up = grid[i][j];
    if(i-1>=0)up+=f(i-1,j,grid,dp);
    else up+=1e9;

    int left = grid[i][j];
    if(j-1>=0)left+=f(i,j-1,grid,dp);
    else left+=1e9;

    return dp[i][j] = min(up, left);
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

    return f(n-1,m-1,grid, dp);
}

// tabulation

#include <bits/stdc++.h> 

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 and j==0)dp[i][j]= grid[i][j];
            else{
                int up = grid[i][j];
                if(i>0) up+=dp[i-1][j];
                else up += 1e9;

                int left = grid[i][j];
                if(j>0) left += dp[i][j-1];
                else left += 1e9;

                dp[i][j] = min(up,left);
            }
        }
    }

    return dp[n-1][m-1];
}
