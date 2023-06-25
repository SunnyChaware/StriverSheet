#include<bits/stdc++.h>
void dfs(int node, vector<int> &vis, vector<int> adj[],
    stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<int> &vis, vector<int> adj[],
vector<int> &ds){
    vis[node] = 1;
    ds.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs2(it,vis,adj,ds);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n];
    for (auto it : edges) {
        adj[it[0]].push_back(it[1]);
    }

    vector<int>vis(n, 0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i, vis, adj, st);
        }
    }

    vector<int> adjT[n];
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
        for (auto it : adj[i]) {
            adjT[it].push_back(i);
        }
    }

    vector<vector<int>>scc;
        while (!st.empty()) {
        int curr = st.top();
        st.pop();
        if (!vis[curr]) {
            vector<int> ds;
            dfs2(curr, vis, adjT, ds);
            scc.push_back(ds);
        }
    }
    return scc;
}
