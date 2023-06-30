#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    if(root==NULL)return {};
    map<int, int> mp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    vector<int> ans;
    while(!q.empty()){
        TreeNode<int> * node = q.front().first;
        int v = q.front().second;
        q.pop();
        if(mp.find(v) == mp.end())mp[v] = node->val;

        if(node->left){
            q.push({node->left, v-1});
        }
        if(node->right){
            q.push({node->right, v+1});
        }
    }
    for(auto it: mp){
        ans.push_back(it.second);
    }
    return ans;
}
