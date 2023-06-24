#include<bits/stdc++.h>
bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<int> adj[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathVis, adj))return true;
            }
            else if(pathVis[it])return true;
        }
        pathVis[node] = 0;
        return false;
    }
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<int> adj[n+1];
  for(auto it: edges){
    adj[it.first].push_back(it.second);
  }
  vector<int> vis(n+1,0), pathVis(n+1,0);
  for(int i=0;i<=n;i++){
    if(!vis[i]){
      if(dfs(i,vis,pathVis,adj))return true;
    }
  }
  return false;
}
