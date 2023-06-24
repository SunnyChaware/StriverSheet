#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode *cloneGraph(graphNode *node)
{
	unordered_map<graphNode *,graphNode *>mp;
	// if empty
    if(node==NULL)return NULL;

	// making a copy of the node and storing it in
	// map so that we wont make it again and pushing to queue
	queue<graphNode *>q;
	graphNode * nn = new graphNode(node->data, {});
	mp[node] = nn;
	q.push(node);

	while(!q.empty()){
		auto curr = q.front();
		q.pop();
		//iterating over nodes
		for(auto it: curr->neighbours){
			// if i havent made a copy of the node
			// then make it
			if(mp.find(it)==mp.end()){
				mp[it] = new graphNode(it->data, {});
				q.push(it);
			}
			// and upadate the neighbors with curr node
			mp[curr]->neighbours.push_back(mp[it]);
		}
	}
	return mp[node];
}
