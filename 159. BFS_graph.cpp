#include <bits/stdc++.h>
void bfs(int src, vector<int> &vis, vector<int>adj[], vector<int> &ans){
    queue<int> q;
    vis[src]=1;
    q.push(src);
    

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto ir: adj[node]){
            if(!vis[ir]){
                vis[ir]=1;
                q.push(ir);
            }
        }
    }
}
vector<int> BFS(int v, vector<pair<int, int>> edges)
{
    vector<int> adj[v];
    for(auto it: edges){
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }
    vector<int> ans;
    vector<int> vis(v,0);

    for(int i=0;i<v;i++){
        if(!vis[i]){
            bfs(i, vis, adj, ans);
        }
    }
    return ans;
}
