bool check(vector<int> &vis, vector<int>adj[],int node, int par)
    {
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                if(check(vis,adj,i,node))return true;
            }
            else{
                if(i!=par)return true;
            }
        }
        return false;
    }
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // if(m==0)return "No";
    vector<int> adj[n+1];
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n+1,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(check(vis,adj,i,-1))return "Yes";
        }
    }
    return "No";
}
