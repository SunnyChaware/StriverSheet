#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();
	// taking i,j in queue where it is zero
	queue<pair<int,int>>q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				q.push({i,j});
			}
		}
	}

	while(!q.empty()){
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		// setting to zero
		for(int i=0;i<n;i++){
			matrix[i][c] = 0;
		}
		for(int i=0;i<m;i++){
			matrix[r][i] = 0;
		}
	}

}
