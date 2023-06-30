#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool f(TreeNode<int> * root, int x,vector<int> &arr){
	if(root==NULL)return false;

	arr.push_back(root->data);
	
	if(root->data == x)return true;
	
	bool l = f(root->left,x,arr);
	bool r = f(root->right,x,arr);
	
	if(l || r)return true;
	arr.pop_back();
	return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> arr;
	if(root==NULL)
	return arr;
	f(root,x,arr);
	return arr;
}
