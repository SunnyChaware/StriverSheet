#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void fin(BinaryTreeNode<int> *root, vector<int> &ans){
    if(root==NULL)return;

    fin(root->left, ans);
    ans.push_back(root->data);
    fin(root->right, ans);
}
void fpre(BinaryTreeNode<int> *root, vector<int> &ans){
    if(root==NULL)return;

    ans.push_back(root->data);
    fpre(root->left, ans);
    fpre(root->right, ans);
}
void f(BinaryTreeNode<int> *root, vector<int> &ans){
    if(root==NULL)return;

    f(root->left, ans);
    f(root->right, ans);
    ans.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans;
    vector<int> ino, pre, post;

    fin(root, ino);
    fpre(root, pre);
    f(root, post);

    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(post);

    return ans;
}
