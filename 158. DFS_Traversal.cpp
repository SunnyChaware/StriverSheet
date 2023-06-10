#include<bits/stdc++.h>

void dfs(int src, vector<int>&vis, vector<int> adj[], 
vector<int> &temp){
    vis[src] = 1;
    temp.push_back(src);
    for(auto it: adj[src]){
        if(!vis[it]){
            dfs(it, vis,adj, temp);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<vector<int>>ans;
    vector<int>vis(V,0);
    int c=0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            c++;
            vector<int> temp;
            dfs(i,vis,adj,temp);
            ans.push_back(temp);
        }
    }
    // ans.insert(ans.begin(),{c});
    return ans;
}
