#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    vector<vector<int>>vis(n, vector<int> (m, 0));
    queue<pair<int,pair<int,int>>>q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
              q.push({0, {i, j}});
              vis[i][j] = 1;
            }
        }
    }
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};

    int time = 0;

    while(!q.empty()){
        int t = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        time = max(time, t);

        for(int i=0;i<4;i++){
            int nr = dr[i] + r;
            int nc = dc[i] + c;

            if(nr>=0 and nr<n and nc>=0 and nc<m and vis[nr][nc]==0 and grid[nr][nc]==1){
                q.push({t+1,{nr,nc}});
                vis[nr][nc] =1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 and grid[i][j]==1){
                return -1;
            }
        }
    }
    return time;
}
