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

/*You are given a binary tree. The binary tree is represented using the TreeNode class. Each TreeNode has an integer value and left and right children, represented using the TreeNode class itself. Convert this binary tree into a binary search tree.*/

void inOrder(TreeNode *root, vector<int> &inorder)
{
    if (root)
    {
        inOrder(root->left, inorder);
        inorder.push_back(root->val);
        inOrder(root->right, inorder);
    }
}

void constructBST(TreeNode *root, vector<int> &inorder, int &i)
{
    if (root)
    {
        constructBST(root->left, inorder, i);
        root->val = inorder[i++];
        constructBST(root->right, inorder, i);
    }
}

void convertBtToBST(TreeNode *root)
{
    vector<int> inorder;
    inOrder(root, inorder);
    sort(inorder.begin(), inorder.end());
    int i = 0;
    constructBST(root, inorder, i);
}

/*
Given a Binary Search Tree with all unique values and two keys. Find the distance between two nodes in BST. The given keys always exist in BST.
*/

int distancefromRoots(TreeNode *root, int x)
{
    if (root->val == x)
        return 0;
    else if (x < root->val)
        return 1 + distancefromRoots(root->left, x);
    return 1 + distancefromRoots(root->right, x);
}
int distanceBtw2Keys(TreeNode *root, int key1, int key2)
{
    if (!root)
        return 0;
    if (key1 > key2)
        swap(key1, key2);
    if (key1 < root->val && key2 < root->val)
    {
        return distanceBtw2Keys(root->left, key1, key2);
    }
    if (key1 > root->val && key2 > root->val)
    {
        return distanceBtw2Keys(root->right, key1, key2);
    }

    if (key1 <= root->val && key2 >= root->val)
    {
        return distancefromRoots(root, key1) + distancefromRoots(root->right, key2);
    }
    return -1;
}

/*Write a program to convert a binary tree to a doubly linked list.*/

void solve(TreeNode *root, TreeNode *&prev, TreeNode *head)
{
    if (!root)
        return;
    solve(root->left, prev, head);
    if (prev == NULL)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    solve(root->right, prev, head);
}

TreeNode *convertBtToDLL(TreeNode *root)
{
    TreeNode *prev = NULL, *head = NULL;
    solve(root, prev, head);
    return head;
}

/*
Write a program to connect nodes at the same level.
*/

vector<TreeNode *> connectNodeAtSameLevel(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    vector<TreeNode *> ans;
    while (!q.empty())
    {
        int sz = q.size();
        TreeNode *var = NULL, *mov;
        for (int i = 0; i < sz; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            if (i == 0)
            {
                var = temp;
                mov = temp;
                temp->left = NULL;
                continue;
            }
            temp->left = NULL;
            mov->right = temp;
            mov = mov->right;
        }
        mov->right = NULL;
        ans.push_back(var);
    }
    return ans;
}