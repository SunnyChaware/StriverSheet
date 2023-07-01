/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
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
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool f(BinaryTreeNode<int>* r1, BinaryTreeNode<int>* r2){
    if(r1 == NULL || r2 == NULL){
        return r1 == r2;
    }
    if(r1->data != r2->data)return false;

    return f(r1->left,r2->right) and f(r1->right,r2->left);

}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root==NULL)return true;
    return f(root->left, root->right);
}
