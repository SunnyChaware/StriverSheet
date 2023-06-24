#include <bits/stdc++.h> 
void topo(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]){
    vis[node] =1;
    for(auto it: adj[node]){
        if(!vis[it])
        {
            topo(it,st,vis,adj);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans, vis(v,0);
    stack<int> st;

    vector<int> adj[v+1];
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
    }

    for(int i=0;i<v;i++){
        if(!vis[i]){
            topo(i,st,vis, adj);
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
