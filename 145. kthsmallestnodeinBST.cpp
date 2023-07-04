void inorder(TreeNode<int> *root, vector<int> &nodes)
{
	if (root == NULL){
		return;
	}

	inorder(root->left, nodes);

	nodes.push_back(root->data);

	inorder(root->right, nodes);
}

int kthSmallest(TreeNode<int> *root, int k)
{
	vector<int> nodes;
	inorder(root, nodes);

	return nodes[k - 1];
}
