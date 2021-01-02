#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* newRoot = new TreeNode(0);
    TreeNode* ptr = newRoot;
    void makeIncreasingSearchTree(TreeNode* root){
        if(root == nullptr)
            return;
        makeIncreasingSearchTree(root->left);
        ptr->right = new TreeNode(root->val);
        ptr = ptr->right;
        makeIncreasingSearchTree(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        makeIncreasingSearchTree(root);
        return newRoot->right;//exclude the first node with default value
    }
};