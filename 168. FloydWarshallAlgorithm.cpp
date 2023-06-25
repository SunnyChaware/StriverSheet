int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    
    vector<vector<int>> adj(n, vector<int> (n,1e9));
    for(auto it: edges){
        adj[it[0]-1][it[1]-1] = it[2];
    }

    for(int k=0; k<n; k++){
        for(int i=0;i<n;i++){
            for(int j = 0; j<n;j++){
                if(i==j)adj[i][j]=0;
                else adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    if(adj[src-1][dest-1]>=1e8)return 1e9;
    else return adj[src-1][dest-1];
}
