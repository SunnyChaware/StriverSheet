#include <bits/stdc++.h> 

class DisjointSet{
    public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void merge(int u, int v){
        int uu = findUPar(u);
        int vv = findUPar(v);
        
        if(uu == vv) return ;
        if(size[uu]<size[vv]){
            parent[uu] = vv;
            size[vv] += size[uu];
        }
        else {
            parent[vv] = uu;
            size[uu] += size[vv];
        }
    }
};

bool cmp(vector<int> &a, vector<int> &b){
	return a[2]<b[2];
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	sort(graph.begin(), graph.end(), cmp);
	DisjointSet ds(n);
	int sum = 0;
	for(auto it: graph){
		if(ds.findUPar(it[0]) != ds.findUPar(it[1])){
			sum+=it[2];
			ds.merge(it[1], it[0]);
		}
	}
	return sum;
}
