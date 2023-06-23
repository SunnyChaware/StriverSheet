#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void f(TreeNode<int>* root, int lvl, vector<int>&res){
    if(root==NULL)return;

    if(res.size()==lvl){
        res.push_back(root->data);
    }

    f(root->left,lvl+1,res);
    f(root->right, lvl+1, res);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int>res;
    f(root,0, res);
    return res;
}
