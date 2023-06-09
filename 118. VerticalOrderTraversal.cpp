// coding ninja

#include <map>

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> result;

    if (root == NULL)
    {
        return result;
    }

    map<int, vector<int>> store;

    int hd = 0;

    queue<pair<TreeNode<int> *, int>> level;

    level.push(make_pair(root, hd));

    while (level.empty() == false)
    {
        pair<TreeNode<int> *, int> temp = level.front();
        level.pop();

        hd = temp.second;

        TreeNode<int> *node = temp.first;

        store[hd].push_back(node->data);

        if (node->left != NULL)
        {
            level.push(make_pair(node->left, hd - 1));
        }

        if (node->right != NULL)
        {
            level.push(make_pair(node->right, hd + 1));
        }
    }

    map<int, vector<int>>::iterator it;

    for (it = store.begin(); it != store.end(); it++)
    {
        for (int i = 0; i < it->second.size(); ++i)
        {
            result.push_back(it->second[i]);
        }
    }

    return result;
}



// mine

see strivers vdo
multiset one easy approach 
