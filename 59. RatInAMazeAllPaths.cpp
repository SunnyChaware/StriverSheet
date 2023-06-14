#include <bits/stdc++.h> 
void fit(vector<vector<int>> &vis, vector<vector<int>> &ans, int n){
  vector<int> ds;
  for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
          ds.push_back(vis[i][j]);
      }
  }
  ans.push_back(ds);
}

void f(vector<vector<int> > &maze ,vector<vector<int> > &vis, int x, int y,
int n, vector<vector<int> > &ans){
  
  if(x == n-1 and y == n-1){
    vis[x][y] = 1;
    fit(vis,ans,n);
    return;
  }

  if(x<0 or x>n-1 or y<0 or y>n-1)return;
  if(vis[x][y]==1 or maze[x][y]==0)return;

  vis[x][y] = 1;
  f(maze,vis,x-1,y,n,ans);
  f(maze,vis,x+1,y,n,ans);
  f(maze,vis,x,y-1,n,ans);
  f(maze,vis,x,y+1,n,ans);
  vis[x][y] = 0;

}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int> > ans;
  vector<vector<int> > vis(n, vector<int> (n, 0));
  f(maze,vis,0,0,n,ans);
  return ans;
}
