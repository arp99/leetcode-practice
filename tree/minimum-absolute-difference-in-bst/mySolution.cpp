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
    int minVal = INT_MAX,prev = -1;
    //do inorder traversal while doing get diff between prev and find min on the go
    //as inorder on bst gives the sorted nodes
    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        if(prev!=-1)
            minVal  = min(minVal,root->val - prev);
        prev = root->val;
        inOrder(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        return minVal;
    }
};