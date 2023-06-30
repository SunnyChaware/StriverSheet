#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

	if(!root)return {};
    map<int, int> mp;
	queue<pair<BinaryTreeNode<int>*, int>>q;
	q.push({root, 0});

	while(!q.empty()){
		BinaryTreeNode<int>* node = q.front().first;
		int l = q.front().second;
		q.pop();

		mp[l] = node->data;

		if(node->left){
			q.push({node->left, l-1});
		}
		if(node->right){
			q.push({node->right, l+1});
		}
	}
	vector<int> ans;
	for(auto it: mp){
		ans.push_back(it.second);
	}
	return ans;

}
