#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

int getMaxWidth(TreeNode<int> *root)
{
    if(!root)return 0;
    int maxi = -1;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        maxi = max(maxi, size);

        for(int i=0;i<size;i++){
            auto node = q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
    return maxi;
}
