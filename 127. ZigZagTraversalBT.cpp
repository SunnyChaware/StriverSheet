#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    if(root==nullptr)return {};
    int ltr = true;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty()){
        int size = q.size();
        vector<int> temp(size);
        for(int i=0;i<size;i++){
            auto node = q.front();
            q.pop();
            if(ltr){
                temp[i] = node->data;
            }
            else temp[size-i-1] = node->data;

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        for(auto it: temp){
            ans.push_back(it);
        }
        ltr = !ltr;
    }
    return ans;
}
