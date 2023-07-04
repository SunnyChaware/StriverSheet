#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* build(int &i, vector<int> &arr, int bound){
    if(i==arr.size() || arr[i]>bound)return NULL;

    TreeNode<int> * root = new TreeNode<int>(arr[i++]);
    root->left = build(i, arr, root->data);
    root->right = build(i, arr, bound);

    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int i = 0;
    return build(i, preOrder, INT_MAX);
}
