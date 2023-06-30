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
Given a binary tree, your task is to find subtree with maximum sum in tree.
*/
int ans = INT_MIN;
int solve(TreeNode *root)
{
    if (!root)
        return 0;

    int subSum = root->val + solve(root->left) + solve(root->right);
    ans = max(ans, subSum);

    return subSum;
}

int maxSumSubtree(TreeNode *root)
{
    solve(root);
    return ans;
}

/*
Construct the BST (Binary Search Tree) from its given level order traversal.
*/
TreeNode *makeBST(TreeNode *root, int data)
{
    if (!root)
    {
        return new TreeNode(data);
    }
    if (data <= root->val)
    {
        root->left = makeBST(root->left, data);
    }
    else
    {
        root->right = makeBST(root->right, data);
    }
}

TreeNode *makeBSTFromLOT(vector<int> arr)
{
    TreeNode *root = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        root = makeBST(root, arr[i]);
    }
    return root;
}

/*
Given an array of size n. The problem is to check whether the given array can represent the level order traversal of a Binary Search Tree or not.
*/
void levelOrderTraversal(TreeNode *root, vector<int> &ans)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            ans.push_back(temp->val);
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

bool checkBSTFromArr(vector<int> arr)
{
    TreeNode *root = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        root = makeBST(root, arr[i]);
    }
    vector<int> ans;
    levelOrderTraversal(root, ans);
    if (arr == ans)
        return true;
    return false;
}