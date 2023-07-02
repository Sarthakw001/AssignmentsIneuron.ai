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
Given a Binary Tree (Bt), convert it to a Doubly Linked List(DLL). The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be the same as in Inorder for the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.
*/

void solve(TreeNode *root, TreeNode *head, TreeNode *prev)
{
    if (!root)
        return;
    solve(root->left, head, prev);
    if (head == NULL)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    solve(root->right, head, prev);
}

TreeNode *binaryTreeToDLL(TreeNode *root)
{
    TreeNode *head = NULL, *prev = NULL;
    solve(root, head, prev);
    return head;
}

/*A Given a binary tree, the task is to flip the binary tree towards the right direction that is clockwise. See the below examples to see the transformation.

In the flip operation, the leftmost node becomes the root of the flipped tree and its parent becomes its right child and the right sibling becomes its left child and the same should be done for all left most nodes recursively.*/

TreeNode *flipTreeClockwise(TreeNode *root)
{
    if (!root)
        return root;
    if (!root->left && !root->right)
        return root;

    TreeNode *flipedNode = flipTreeClockwise(root->left);

    root->left->left = root->right;
    root->left->right = root;
    root->left = root->right = NULL;

    return flipedNode;
}

/*
Given a binary tree, print all its root-to-leaf paths without using recursion. For example, consider the following Binary Tree.
*/

void printRootToLeafPath(TreeNode *root, vector<int> &path)
{
    if (!root)
        return;
    path.push_back(root->val);
    if (!root->left && !root->right)
    {
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << "->";
        }
        cout << endl;
    }
    printRootToLeafPath(root->left, path);
    printRootToLeafPath(root->right, path);
    path.pop_back();
}

/*
Given Preorder, Inorder and Postorder traversals of some tree. Write a program to check if they all are of the same tree.
*/

TreeNode *constructTree(vector<int> &preorder, vector<int> &inorder)
{
}
bool comparePostorder(TreeNode *root, vector<int> &postorder, int i)
{
    if (root)
    {
        bool left = comparePostorder(root->left, postorder, i);
        bool right = comparePostorder(root->right, postorder, i);
        if (i < postorder.size() && root->val != postorder[i])
            return false;
        i++;
        if (left && right)
            return true;
        else
            return false;
    }
}
bool checkIfPPI(vector<int> &preorder, vector<int> &inorder, vector<int> &postorder)
{
    TreeNode *root = constructTree(preorder, inorder);
    if (comparePostorder(root, postorder, 0))
        return true;
    return false;
}