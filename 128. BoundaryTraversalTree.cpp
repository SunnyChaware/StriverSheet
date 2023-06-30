#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isleaf(TreeNode<int> * root){
    if(root->left==NULL and root->right==NULL){
        return true;
    }
    return false;
}
void left(TreeNode<int> *root, vector<int> &ans){
    TreeNode<int> *cur = root->left;
    while(cur){
        if(!isleaf(cur))ans.push_back(cur->data);
        if(cur->left){
            cur = cur->left;
        }
        else cur = cur->right;
    }
}
void right(TreeNode<int> *root, vector<int> &ans){
    TreeNode<int> *cur = root->right;
    vector<int> temp;
    while(cur){
        if(!(isleaf(cur)))temp.push_back(cur->data);
        if(cur->right){
            cur = cur->right;
        }
        else cur = cur->left;
    }
    for(int i=temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
}
void leaf(TreeNode<int> * root, vector<int> &ans){
    if(isleaf(root)){
        ans.push_back(root->data);
        return;
    }

    if(root->left)leaf(root->left, ans);
    if(root->right)leaf(root->right, ans);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(!root)return ans;
    if(!isleaf(root))ans.push_back(root->data);
    left(root, ans);
    leaf(root, ans);
    right(root, ans);

    return ans;
}
