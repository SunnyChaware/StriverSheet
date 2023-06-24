#include<bits/stdc++.h>
void dfs(int r, int c, vector<vector<int>> &ans, 
vector<vector<int>> &image, int n, int m, int cc, int nc, int dr[], int dc[]){

    ans[r][c] = nc;

    for(int i=0;i<4;i++){
        int x = dr[i]+r;
        int y = dc[i]+c;

        if(x>=0 and x<n and y>=0 and y<m and image[x][y]==cc and ans[x][y]!=nc){
            dfs(x,y,ans,image,n,m,cc,nc,dr,dc);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int nc)
{
    int n = image.size();
    int m = image[0].size();
    int cc = image[x][y];
    vector<vector<int>> ans = image;

    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};

    dfs(x,y,ans,image,n,m,cc,nc,dr,dc);

    return ans;
}
