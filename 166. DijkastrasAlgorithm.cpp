#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int v, int edges, int source) {
    vector<pair<int,int>> adj[v+1];
    for(auto it: vec){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    vector<int> dis(v,INT_MAX);
    dis[0] = 0;
    set<pair<int,int>> st;
    st.insert({0, 0}); 

    while(!st.empty()){
        auto it = *(st.begin());
        int d = it.first;
        int node = it.second;
        st.erase(it);

        for(auto it: adj[node]){
            int adjNode = it.first;
            int edW = it.second;

            if(edW + d < dis[adjNode]){
                dis[adjNode] = edW + d;
                st.insert({edW+d, adjNode});
            }
        }
    }
    return dis;
}
