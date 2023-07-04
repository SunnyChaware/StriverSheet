#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
int ip(BinaryTreeNode<int>* root, int key){
    int pred = -1;

    if(root == NULL)
    return pred;

    
    while(root){
        if(root->data >= key){
            root = root->left;
        } else {
            pred = root->data;
          root = root->right;
        }
    }
    return pred;
}
int is(BinaryTreeNode<int>* root, int key){
    int succ = -1;

    if(root == NULL)
    return succ;

    
    while(root){
        if(root->data > key){
            succ = root->data;
            root = root->left;
        }
        else root = root->right;
    }
    return succ;
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    pair<int,int> ans;
    ans.first = ip(root, key);
    ans.second = is(root, key);

    return ans;
}
