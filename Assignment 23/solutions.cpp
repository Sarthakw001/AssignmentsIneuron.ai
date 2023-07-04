#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

/*
Given preorder of a binary tree, calculate its **[depth(or height)](https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/)** [starting from depth 0]. The preorder is given as a string with two possible characters.

1. ‘l’ denotes the leaf
2. ‘n’ denotes internal node

The given tree can be seen as a full binary tree where every node has 0 or two children. The two children of a node can ‘n’ or ‘l’ or mix of both.

**Examples :**

Input  : nlnll
Output : 2
Explanation :
*/
int solve(string tree, int n, int &idx)
{
    if (idx >= n || tree[idx] == 'l')
        return 0;

    idx++;
    int left = solve(tree, n, idx);

    idx++;
    int right = solve(tree, n, idx);

    return max(left, right) + 1;
}

int depthOfBinaryTree(string tree)
{
    int n = tree.length(), i = 0;
    return solve(tree, n, i);
}

/*
<aside>
💡 Question-2:

Given a Binary tree, the task is to print the **left view** of the Binary Tree. The left view of a Binary Tree is a set of leftmost nodes for every leve

</aside>
*/

void solve(TreeNode *root, vector<int> &ds, int level)
{
    if (root)
    {
        if (ds.size() == level)
        {
            ds.push_back(root->val);
        }
        solve(root->left, ds, level + 1);
        solve(root->right, ds, level + 1);
    }
}

vector<int> leftView(TreeNode *root)
{
    vector<int> ds;
    int level = 0;
    solve(root, ds, level);
    return ds;
}

/*
Given a Binary Tree, print the Right view of it.

The right view of a Binary Tree is a set of nodes visible when the tree is visited from the Right side.
*/

void solve(TreeNode *root, vector<int> &ds, int level)
{
    if (root)
    {
        if (ds.size() == level)
        {
            ds.push_back(root->val);
        }
        solve(root->left, ds, level + 1);
        solve(root->right, ds, level + 1);
    }
}

vector<int> rightView(TreeNode *root)
{
    vector<int> ds;
    int level = 0;
    solve(root, ds, level);
    return ds;
}

/*
Given a Binary Tree, The task is to print the bottom view from left to right. A node x is there in output if x is the bottommost node at its horizontal distance. The horizontal distance of the left child of a node x is equal to a horizontal distance of x minus 1, and that of a right child is the horizontal distance of x plus 1.
*/

vector<int> bottomView(TreeNode *root)
{
    queue<pair<int, TreeNode *>> q;
    map<int, int> mp;
    q.push({0, root});
    while (!q.empty())
    {
        int level = q.front().first;
        TreeNode *node = q.front().second;
        q.pop();
        mp[level] = node->val;

        if (node->left)
        {
            q.push({level - 1, node->left});
        }
        if (node->right)
        {
            q.push({level + 1, node->right});
        }
    }

    vector<int> ans;
    for (auto x : mp)
    {
        ans.push_back(x.second);
    }
    return ans;
}