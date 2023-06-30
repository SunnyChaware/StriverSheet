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
#include<bits/stdc++.h>
int f(TreeNode<int> *root, int &maxi){
    if(root==NULL)return 0;

    int lh = f(root->left, maxi);
    int rh = f(root->right, maxi);

    maxi = max(maxi, lh+rh);

    return 1+max(lh, rh);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    int maxi = 0;
	f(root, maxi);
    return maxi;
}
