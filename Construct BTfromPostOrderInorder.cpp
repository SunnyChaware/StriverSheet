 #include<bits/stdc++.h>
TreeNode<int>* bt(vector<int>& io, int is, int ie, vector<int>& po, int ps, int pe, map<int,int> &mp){
     if(ps>pe || is>ie)return NULL;

     TreeNode<int> * root = new TreeNode<int> (po[pe]);

     int inRoot = mp[po[pe]];
     int nodesleft = inRoot-is;

     root->left = bt(io, is, inRoot+1, po, ps, ps+nodesleft-1, mp);
     root->right = bt(io, inRoot+1, ie, po, ps+nodesleft, pe-1, mp);

     return root;
} 


TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
     if(inOrder.size()!=postOrder.size())return NULL;
	map<int, int> mp;
     for(int i=0;i<inOrder.size();i++){
          mp[inOrder[i]] = i;
     }

     TreeNode<int> * root = bt(inOrder, 0, inOrder.size()-1, postOrder, 0, postOrder.size()-1, mp);

     return root;
}
