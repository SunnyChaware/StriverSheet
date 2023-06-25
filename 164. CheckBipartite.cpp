#include<bits/stdc++.h>
bool bfs(int node, int V, vector<int>adj[], vector<int> &color)
    {
        color[node]=0;
        queue<int> q;   
        q.push(node);
        
        while(q.empty()==false)
        {
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]){
                if(color[it]==-1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[node] == color[it])return false;
            }
        }
        return true;
    }
bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n = edges.size();
	int m = edges[0].size();
	vector<int>adj[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(edges[i][j] == 1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		} 
	}

	vector<int> color(n,-1);
	for(int i=0;i<n;i++){
		if(color[i]==-1){
			if(bfs(i,n,adj,color)==false)return false;
		}
	}
	return true;
}
