#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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
int f(TreeNode<int> * root, int k, int &c){
    if(root==NULL)return -1;

    int right = f(root -> right, k, c);
    if(right!=-1){
        return right;
    }
    c++;
    if(c==k)return root->data;
    int left = f(root->left, k, c);
    return left;
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int c = 0;
    return f(root,k,c);
}
